//
//  初始化列表.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/8/9.
//

#include <stdio.h>
#include <iostream>
using namespace std;

struct Test1{
    Test1(){
        cout << "test1 默认构造函数" << endl;
    }
    Test1(const Test1& t1){
        cout << "test1 拷贝构造函数" << endl;
    }
    Test1& operator = (const Test1& t1){
        cout << "test1 赋值运算符重载" << endl;
        return *this;
    }

};
struct Test2{
    Test2(){
        cout << "test2 默认构造函数" << endl;
    }
    Test1 t;
    Test2(Test1& t1){
        // 用test1的默认构造函数初始化t
        t = t1;
        cout << "test2 转换构造函数" << endl;
    }
};

struct Test3{
    Test3(){
        cout << "test3 默认构造函数" << endl;
    }
    Test1 t;
    // 用初始化列表初始化t
    Test3(Test1& t1): t(t1){
        cout << "test3 转换构造函数" << endl;
    }
};

struct Test11{
    Test11(int a){
        cout << "test11 有参构造函数" << a << endl;
    }
    Test11(const Test11& t11){
        cout << "test11 拷贝构造函数" << endl;
    }
    Test11& operator = (const Test11& t11){
        cout << "test11 赋值运算符重载" << endl;
        return *this;
    }

};

struct Test4{
    // 编译报错，因为Test11没有默认构造函数
//    Test4(){
//        cout << "test4 默认构造函数" <<  endl;
//    }
    
    Test11 t;
    

    // 用初始化列表初始化t，如果不存在时下面这个函数，编译报错
    Test4(Test11& t1): t(t1){
        cout << "test3 转换构造函数" << endl;
    }
};


int main(){
    Test1 t1;
    /*
     test1 默认构造函数
     */
    
    cout << endl;
    Test2 t2(t1);
    /*
     test1 默认构造函数
     test1 赋值运算符重载
     test2 转换构造函数
     */
    
    cout << endl;
    Test3 t3(t1);
    /*
     test1 拷贝构造函数
     test3 转换构造函数
     */
    
    cout << endl;
    Test11 t11(1);
    /*
     test11 有参构造函数1
     */
    
    cout << endl;
    Test4 t4(t11);
    /*
     test11 拷贝构造函数
     test3 转换构造函数
     */
    
    return 0;
}
