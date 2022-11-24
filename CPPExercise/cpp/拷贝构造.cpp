//
//  构造析构2.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/9/11.
//

#include<iostream>
using namespace std;

class A{
    int a;
public:
    A(int i = 0):a(i){
        cout << a ;
    }
    A(A&P):a(P.a){
        cout << "*";
    }
};

void f2(A t){
    A c(t);
    throw -1;
}

void f1(A &p){
    try{
        f2(p);
    }catch(int){
        cout << "#" << endl;
    }
}

int main(){
    A c1; // 调用A构造函数，输出0
    f1(c1); // f1->A的拷贝构造*->f2->A拷贝构造*->#
    return 0;
}

// 0**#
