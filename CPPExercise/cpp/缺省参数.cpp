//
//  缺省参数.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/8/9.
//

#include <stdio.h>
#include <iostream>
using namespace std;

// 声明给出
void fun1(int a = 1, int b = 2, int c = 3);

// 编译报错，重复声明
//void fun1(int a = -1, int b = -2, int c = -3){
//    cout << a << " " << b << " " << c << endl;
//}

void fun1(int a, int b, int c){
    cout << a << " " << b << " " << c << endl;
}

// 声明定义一起给出
void fun2(int a, int b = 22, int c = 33){
    cout << a << " " << b << " " << c << endl;
}

class A{
public:
    virtual void afun(int a = 111, int b = 222){
        cout << "A:afun: " << a << " " << b << endl;
    };
};
class B: public A{
public:
    void afun(int a = 333, int b = 444){
        cout << "B:afun: " << a << " " << b << endl;
    }
};

int main(){
    fun1(); // 1 2 3
    fun1(5); // 5 2 3
    
    fun2(10); // 10 22 33
    
    B* objBb = new B();
    objBb->afun(); // B:afun: 333 444
    
    A* objAb = new B();
    objAb->afun(); // B:afun: 111 222
    return 0;
}
