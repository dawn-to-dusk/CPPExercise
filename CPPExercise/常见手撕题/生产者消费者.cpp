//
//  生产者消费者.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/8/29.
//


#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
using namespace std;

//static const int bufSize = 10

class BoundedBuffer {
public:
//  BoundedBuffer(const BoundedBuffer& rhs) = delete;
//  BoundedBuffer& operator=(const BoundedBuffer& rhs) = delete;

  BoundedBuffer(size_t size)
      : begin(0), end(0), buffered(0), buf(size) {
  }

  void Produce(int n) {
    {
      unique_lock<mutex> lock(mtx);
      // 等待缓冲不为满。
      not_full.wait(lock, [=] { return buffered < buf.size(); });

      // 插入新的元素，更新下标。
      buf[end] = n;
      end = (end + 1) % buf.size();

      ++buffered;
    }  // 通知前，自动解锁。

    // 通知消费者。
    not_empty.notify_one();
  }

  int Consume() {
    unique_lock<std::mutex> lock(mtx);
    // 等待缓冲不为空。
    not_empty.wait(lock, [=] { return buffered > 0; });

    // 移除一个元素。
    int n = buf[begin];
    begin = (begin + 1) % buf.size();

    --buffered;

    // 通知前，手动解锁。
    lock.unlock();
    // 通知生产者。
    not_full.notify_one();
    return n;
  }

private:
  size_t begin;
  size_t end;
  size_t buffered;
  vector<int> buf;
  condition_variable not_full;
  condition_variable not_empty;
  mutex mtx;
};

BoundedBuffer g_buffer(2);
mutex g_io_mutex;

void Producer(){
    int n = 0;
    while(n < 100000){
        g_buffer.Produce(n);
        if((n % 10000) == 0){
            unique_lock<mutex> lock(g_io_mutex);
        }
        n++;
    }
    g_buffer.Produce(-1);
}

void Consumer() {
  std::thread::id thread_id = std::this_thread::get_id();

  int n = 0;
  do {
    n = g_buffer.Consume();
    if ((n % 10000) == 0) {
      std::unique_lock<std::mutex> lock(g_io_mutex);
      std::cout << "Consume: " << n << " (" << thread_id << ")" << std::endl;
    }
  } while (n != -1);  // -1 表示缓冲已达末尾。

  // 往缓冲里再放一个 -1，这样其他消费者才能结束。
  g_buffer.Produce(-1);
}

int main() {
  std::vector<std::thread> threads;

  threads.push_back(std::thread(&Producer));
  threads.push_back(std::thread(&Consumer));
  threads.push_back(std::thread(&Consumer));
  threads.push_back(std::thread(&Consumer));

  for (auto& t : threads) {
    t.join();
  }

  return 0;
}
