//
//  类型转换函数.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/8/8.
//

#include <stdio.h>
#include <iostream>
using namespace std;

class A{
public:
    A(){
        cout << "A 默认构造函数" << endl;
    }
    A(int a_val){
        this->a_val = a_val;
        cout << "A 传参构造函数（转换构造函数）" << endl;
    }
    int a_val;
};

class B{
public:
    B(){
        cout << "B 默认构造函数" << endl;
    }
    B(const A& a){ // 转换构造函数
        b_val = a.a_val;
        cout << "B 转换构造函数" << endl;
    }
    operator A(){ // 类型转换函数
        cout << "B 类型转换函数" << endl;
        return A(b_val);
    }
    void print(){
        cout << b_val << endl;
    }
    int b_val;
};

class B1{
public:
    explicit B1(){
        cout << "B1 默认构造函数" << endl;
    }
    explicit B1(const A& a){ // 转换构造函数
        b_val = a.a_val;
        cout << "B1 转换构造函数" << endl;
    }
    explicit operator A(){ // 类型转换函数
        cout << "B1 类型转换函数" << endl;
        return A(b_val);
    }
    void print(){
        cout << b_val << endl;
    }
    int b_val;
};

int main(){
    A objA; // 调用A默认构造函数
    cout << endl;
    B objB = objA; // 隐式调用B的转换构造函数
    cout << endl;
    objA = objB; // 隐式调用B的类型转换函数，内部调用A的传参构造函数
    cout << endl;
    
    cout << "explicit ====== " << endl;
    cout << endl;
    
    B1 objB11; // 可以调用，explicit修饰无用
    cout << endl;
    // 编译不通过，不可以隐式调用
    //B1 objB1 = objA;
    B1 objB1(objA); // 只能显式调用
    cout << endl;
    // 编译不通过，不可以隐式调用
    //objA = objB1;
    objA = objB.operator A();// 只能显式调用
    return 0;
}
