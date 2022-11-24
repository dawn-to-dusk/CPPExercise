//
//  main函数之前运行的函数.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/8/10.
//

#include <stdio.h>
#include <iostream>
using namespace std;

// 1 gcc扩展
__attribute__((constructor)) void before1(){
    cout << "before 1" << endl;
}
__attribute__((destructor)) void after1(){
    cout << "after 1" << endl;
}

// 2 static变量的初始化在main之前
int before2(){
    cout << "before 2" << endl;
    return 2;
}
static int a = before2();

// 3 静态对象的构造函数
class X{
public:
    X(){
        cout << "X构造函数" << endl;
    }
    ~X(){
        cout << "X析构函数" << endl;
    }
};
static X x;

// 4 lambda表达式，匿名函数，相当于一个全局对象的初始化
int b = []{
    cout << "before 4" << endl;
    return 0;
}();

int main(){
    cout << "main 函数" << endl;
    return 0;
}

/*
 before 1
 before 2
 X构造函数
 before 4
 main 函数
 after 1
 X析构函数
 */
