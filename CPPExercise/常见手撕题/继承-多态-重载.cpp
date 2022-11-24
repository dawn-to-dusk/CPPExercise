//
//  继承-多态-重载.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/8/28.
//

#include<iostream>
using namespace std;

class Animal{
public:
    // 虚函数
    virtual void eat(int a, int b){
        cout << "annimal eat" << endl;
    }
};

class Dog: public Animal{
public:
    // 重写，多态
    void eat(int a, int b){
        cout << "dog eat1" << endl;
    }
    
    // 重载
    void eat(int a){
        cout << "dog eat2"<< endl;
    }
    
    // 运算符重载(定义为成员函数)
    Dog operator=(const Dog &d1) {
        cout << "=" << endl;
        n = d1.n;
        return *this;
    }
    int n;
    friend void getN(Dog &d){
        cout << "friend " << d.n << endl;
    }
};

// 运算符重载，定义为普通非成员函数
Dog operator+(const Dog &d1, const Dog &d2) {
    cout << "+" << endl;
    Dog d;
    d.n = d1.n + d2.n;
    return d;
}

int main(){
    Animal* dog = new Dog();
    dog->eat(1, 2);
    // 编译报错，dog编译时时不知道是子类对象的，所以无法调用子类重载的eat(1)
    //dog->eat(1);
    
    Dog dog1;
    dog1.eat(1, 2);
    dog1.eat(1);
    Dog dog2;
    dog2 = dog1;
    
    Dog dog3;
    dog3 = dog1 + dog1;
    
    getN(dog3);
    
    return 0;
    
}
