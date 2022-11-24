//
//  缺省参数2.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/8/23.
//

#include<iostream>
using namespace std;

class A{
public:
    virtual void func(int val = 1){
        cout << "A->" << val << endl;
    }
    virtual void test(){
        func();
    }
};

class B : public A{
public:
    void func(int val = 0){
        cout << "B->" << val << endl;
    }
};

int main(){
    B* p = new B;
    p->test(); // B->1
    // 调用test调用的是基类函数，进一步调用func，编译时静态绑定了基类的func及基类的函数缺省值
    // 实际执行时，func动态绑定派生类，所以执行的是派生类的func，但仍然使用基类的缺省值
    
    B* p1 = new B;
    p1->func(); // B->0
    return 0;
}
