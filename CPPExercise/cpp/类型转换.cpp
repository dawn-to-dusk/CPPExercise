//
//  类型转换.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/9/11.
//

#include<iostream>
using namespace std;

class A{
    int i, j;
public:
    A(int x = 0, int y = 1):i(x), j(y){}
    void f(){cout << i + j;}
};

class B : public A {
    double a, b;
public:
    B(int x, int y, int z, int k):A(x,y), a(z), b(k) {}
    void f(){cout<< a * b;}
};

int main(){
    B b(1, 2, 3, 4);
    B &rB = b;
    rB.f(); // 12
    A &rA = static_cast<A &>(b); // 上行安全
    rA.f(); // 3 // 创建B的时候传参数了A(1,2)
    return 0;
}
