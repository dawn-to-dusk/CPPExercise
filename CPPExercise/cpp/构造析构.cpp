//
//  构造析构.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/8/9.
//

#include <stdio.h>
#include <iostream>
using namespace std;

class A{
public:
    A(){
        cout << "A 构造" << endl;
    }
    virtual ~A(){
        cout << "A 析构" << endl;
    }
};

class B{
public:
    B(){
        cout << "B 构造" << endl;
    }
    virtual ~B() = 0;
};
B::~B(){
    cout << "B 析构" << endl;
}

class C: A, B{
public:
    C(){
        cout << "C 构造" << endl;
    }
    ~C(){
        cout << "C 析构" << endl;
    }
};

int main(){
//    C c;
//    cout << endl;
    
    A *as = new A[5];
    delete []as;
    return 0;
}
