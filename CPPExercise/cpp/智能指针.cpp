//
//  智能指针.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/8/7.
//

#include <stdio.h>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]){
    // unique_ptr
//    std::unique_ptr<int> pt1(new int(11));
//    //unique_ptr<int> pt2 = pt1; // 禁止拷贝语义，编译错误
//    cout << *pt1 << endl; // 11
//
//    std::unique_ptr<int> pt3 = std::move(pt1); // move语义转移指针
//    cout << *pt3 << endl; // 11
//    //cout << *pt1 << endl; // 指针已经转移了，运行错误
//
//    pt3.reset(); // 释放指针
//    pt1.reset(); // 不会导致运行错误
//    //cout << *pt3 << endl; // 运行时错误
//
//    unique_ptr<int> pt4(new int(44));
//    cout << *pt4 << endl;
//    pt4.reset(new int(444));
//    cout << *pt4 << endl;
//    pt4 = nullptr; // 显式销毁指针，相当于reset()
//
//    unique_ptr<int> pt5(new int(55));
//    int *p5 = pt5.release();
//    //cout << *pt5 <<endl; // 运行报错
//    cout << *p5 <<endl; // 55
//    delete p5;
    
    // shared_ptr
//    shared_ptr<int> spt1(new int(111));
//    cout << spt1.use_count() <<endl; // 1
//    shared_ptr<int> spt2 = spt1;
//    cout << spt1.use_count() << endl; // 2
//    cout << spt2.use_count() << endl; // 2
//
//    spt1.reset();
//    cout << spt1.use_count() <<endl; //0
//    //cout << *spt1 << endl; // 运行时报错
//    cout << spt2.use_count()<<endl; // 1
//    cout << *spt2 << endl;// 111
    
    // weak_ptr
    shared_ptr<int> spt1(new int(1111));
    weak_ptr<int> wpt1 = spt1;
    cout << *spt1 << endl; // 1111
    //cout << *wpt1 << endl; // 编译报错
    
    cout << spt1.use_count() << endl; // 1
    cout << wpt1.use_count() << endl; // 1
    
    shared_ptr<int> spt2 = wpt1.lock();
    cout << spt2.use_count() << endl; // 2
    cout << *spt2 << endl; // 1111
    spt2.reset();
    cout << spt1.use_count() << endl; // 1
    cout << *spt1 << endl; // 1111
    

    return 0;
}
