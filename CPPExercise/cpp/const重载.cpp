//
//  const重载.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/8/25.
//

#include<iostream>
using namespace std;

class A{
public:
    int fun1(){
        cout << "func1" << endl;
        return 0;
    }
    
    // const修饰函数
    int fun1() const{
        cout << "func11" << endl;
        return 0;
    }
    
    // const修饰返回值
    // 编译器报错：Functions that differ only in their return type cannot be overloaded
//    const int fun1(){
//        cout << "func11" << endl;
//        return 0;
//    }
    
    
    // const修饰普通类型参数
    int fun2(char a){
        cout << "func2" << endl;
        return 0;
    }
    // 编译不通过，都是不可改变的常量
//    int fun2(const char a){
//        cout << "func2" << endl;
//        return 0;
//    }
    
    
    // const 修饰常量指针参数
    int fun3(char * a){
        cout << "func3.1" << endl;
        return 0;
    }
    // 编译不通过，指针指向的都是同一个变量
//    int fun3(char *const a){
//        cout << "func3.2" << endl;
//        return 0;
//    }
    // const修饰指针常量 可以
    int fun3(const char * a){
        cout << "func3.3" << endl;
        return 0;
    }
};

int main(){
    // const 修饰函数
    A a;
    a.fun1(); // func1 非常对象优先调用非常函数
    const A a1;
    a1.fun1(); // func11 常对象只能调用常函数
    
    // const 修饰返回值
}
