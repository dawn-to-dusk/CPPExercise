//
//  const常量.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/9/16.
//

#include<iostream>
using namespace std;


void func(const int * a, const int b){
    cout << *a + b << endl;
}




class A{
    //static int n = 0; // error!
    static int n;
    const int m = 0; // 如果有构造函数，一定要带初始化列表
public:
    
    void funcA(){
        cout << "funcA" << endl;
        cout << n << endl;
        cout << m << endl;
    }
};
int A::n = 2;

class A1{
    static int n;
    const int m = 0; // 构造函数可以不带初始化列表
    const char c = 'c';
public:
    
    void funcA(){
        cout << "funcA1" << endl;
        cout << n << endl;
        cout << m << endl;
        cout << c << endl;
    }
    A1(){
        cout << "A1" << endl;
    }
};
int A1::n = 5;


class A2{
    static int n;
    const int m; // 构造函数可以不带初始化列表
    static const int l;
public:
    
    void funcA(){
        cout << "funcA2" << endl;
        cout << n << endl;
        cout << m << endl;
        cout << l << endl;
    }
    A2():m(22){
        cout << "A2" << endl;
    }
};
int A2::n = 55;
const int A2::l = 66;


int main(){
    int a = 1;
    int b = a;
    const int * ptr1 = &a;
    const int * ptr2 = &b;
    a++;
    
    cout << ptr1 << endl;
    cout << ptr2 << endl;
    cout << *ptr1 << endl;
    cout << *ptr2 << endl;
    
    func(&a, b);
    
    A objA;
    objA.funcA();
    A1 objA1;
    objA1.funcA();
    A2 objA2;
    objA2.funcA();
}
