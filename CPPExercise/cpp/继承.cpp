//
//  继承.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/9/20.
//

#include<iostream>
using namespace std;

class A{
    int a1;
public:
    A():a1(0){}
    void f(){cout << a1 << " ";}
};

class B: public A{
    int b1;
public:
    B():b1(1){}
    void f(){cout << b1 << " ";}
};

int main(){
    B ob1;
    ob1.A::f();
    return 0;
}
