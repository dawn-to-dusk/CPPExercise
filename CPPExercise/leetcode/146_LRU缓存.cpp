//
//  146_LRU缓存.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/8/17.
//

#include<iostream>
#include<map>
using namespace std;

// 双向链表存储
// 哈希表查询

struct Node{
    int key;
    int value;
    Node* pre;
    Node* next;
    Node(){
        key = 0;
        value = 0;
        pre = nullptr;
        next = nullptr;
    }
    Node(int _key, int _value):key(_key), value(_value), pre(nullptr), next(nullptr){}
};

class LRUCache {
public:
    int cap;
    int size;
    unordered_map<int, Node*> cacheMap;
    Node* head;
    Node* tail;
    // 初始化cap、size、head、tail及head\tail的关系
    LRUCache(int capacity) {
        cap = capacity;
        size = 0;
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->pre = head;
    }
    
    // get:找到移到头
    int get(int key) {
        // 没找到
        if(cacheMap.find(key) == cacheMap.end()){
            print();
            return -1;
        }
        // 找到
        // 1 移动到头
        Node* cur = cacheMap[key];
        moveToHead(cur);
        // 2 返回值
        print();
        return cur->value;
    }
    
    // put:
    // - 添加到头，添加哈希表元素，检测容量，删除尾，删除哈希表元素
    // - 更新，移动到头
    void put(int key, int value) {
        if(cacheMap.find(key) == cacheMap.end()){
            // 没找到
            // 1 添加到头
            Node* cur = addToHead(key, value);
            // 2 添加到map
            cacheMap[key] = cur;
            // 3 检查容量
            if(size < cap){
                size++;
            } else{
                // 4 移除尾
                deleteTail();
            }
        } else {
            // 找到
            // 1 修改值
            Node* cur = cacheMap[key];
            cur->value = value;
            // 2 移动到头
            moveToHead(cur);
        }
        print();
    }

    void moveToHead(Node* cur){
        cur->pre->next = cur->next;
        cur->next->pre = cur->pre;
        cur->pre = head;
        cur->next = head->next;
        cur->pre->next = cur;
        cur->next->pre = cur;
    }

    Node* addToHead(int key, int value){
        Node* cur = new Node(key, value);
        cur->pre = head;
        cur->next = head->next;
        head->next = cur;
        cur->next->pre = cur;
        return cur;
    }

    void deleteTail(){
        Node* del = tail->pre;
        cacheMap.erase(del->key);
        tail->pre = del->pre;
        del->pre->next = tail;
        delete del;
    }

    void print(){
        Node* cur = head->next;
        while(cur != tail){
            cout << cur->key << " " << cur->value << endl;
            cur = cur->next;
        }
        cout << "print" << size << endl;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
