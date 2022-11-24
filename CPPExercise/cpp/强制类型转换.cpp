//
//  类型转换.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/8/8.
//

#include <stdio.h>
#include <iostream>
#include <exception>
using namespace std;



class BaseA {
    virtual void dummy() {}
};
class DerivedA: public BaseA {
    int a;
};

class BaseB {
};
class DerivedB: public BaseB {
public:
    DerivedB(){
        a = 1;
    }
    int a;
};

class BaseC {
    virtual void dummy() {}
};
class DerivedC: public BaseC {
public:
    int a;
};

class BaseD {
    virtual void dummy() {}
};
class DerivedD: public BaseD {
public:
    int a;
};
class DerivedD1: public BaseD {
public:
    int a;
};

class BaseE {
    virtual void dummy() {}
};
class DerivedE: public BaseE {
public:
    DerivedE(){
        a = 1;
    }
    int a;
};

int main () {
    try {
        // 上行 ===================
        // 子类转父类，上行均没问题，均不要求虚函数
        DerivedA * pdA = new DerivedA;
        BaseA * pbA;
        pbA = static_cast<BaseA*>(pdA);
        if (pbA==0) {
            cout << "Null pointer on A1 type-cast.\n";
        } else {
            cout << "A1 type-cast ok.\n";
        }
        pbA = dynamic_cast<BaseA*>(pdA);
        if (pbA==0) {
            cout << "Null pointer on A2 type-cast.\n";
        } else {
            cout << "A2 type-cast ok.\n";
        }
        
        // 下行 ===================
        // 父类转子类
        // 1 static下行不安全
        BaseB * pbB = new BaseB;
        DerivedB * pdB;
        pdB = static_cast<DerivedB*>(pbB);
        if (pdB==0) {
            cout << "Null pointer on B type-cast.\n";
        } else {
            // 编译通过但不安全，父类中没有a，所以访问a是不安全的，输出a为0
            cout << pdB->a << endl;
            cout << "B type-cast ok.\n";
        }
        
        // 2 dynamic_cast下行要求父类中有虚函数，否则转换无意义
        // 编译不通过
        //pdB1 = dynamic_cast<DerivedB*>(pbB);
        
        // 3 dynamic_cast下行转换为空指针
        BaseC * pbC = new BaseC;
        DerivedC * pdC;
        pdC = dynamic_cast<DerivedC*>(pbC);
        if (pdC==0) {
            // 父类转换为子类时，因为不安全，直接转换为nullptr
            cout << "Null pointer on C type-cast.\n";
        } else {
            cout << "C type-cast ok.\n";
        }
        
        // 4 dynamic_cast下行交叉转换为空指针
        DerivedD * pdD = new DerivedD;
        DerivedD1 * pdD1;
        // 编译不通过，static_cast不支持交叉转换
        //pdD1 = static_cast<DerivedD1*>(pdD);
        // 转换为空指针
        pdD1 = dynamic_cast<DerivedD1*>(pdD);
        if (pdD1==0) {
            // 父类转换为子类时，因为不安全，直接转换为nullptr
            cout << "Null pointer on D type-cast.\n";
        } else {
            cout << "D type-cast ok.\n";
        }
        
        // 5 多态性，对于指向派生类的基类指针可以被安全转换为派生类指针
        BaseE * pbE = new DerivedE;
        DerivedE* pdE;
        pdE = static_cast<DerivedE*>(pbE);
        if (pdE==0) {
            cout << "Null pointer on E1 type-cast.\n";
        } else {
            // 输出a为1
            cout << pdE->a << endl;
            cout << "E1 type-cast ok.\n";
        }
        pdE = dynamic_cast<DerivedE*>(pbE);
        if (pdE==0) {
            cout << "Null pointer on E2 type-cast.\n";
        } else {
            // 输出a为1
            cout << pdE->a << endl;
            cout << "E2 type-cast ok.\n";
        }
        cout << endl;
        
        
        // const_cast ==============
        int array[4] = {1, 2, 3, 4};
        for(int i = 0; i < 4; i++){
            cout << array[i] << " ";
        }
        cout << endl;
        // 定义常量数组的指针
        const int* ptr_array = array;
        // 编译错误，常量数组不允许修改
        // ptr_array[0] = 2;
        
        int* ptr_array1 = const_cast<int*>(ptr_array); // 常量数组去常量
        ptr_array1[0] = 2;
        
        // 2 2 3 4
        for(int i = 0; i < 4; i++){
            cout << array[i] << " ";
        }
        cout << endl;
        // 2 2 3 4
        for(int i = 0; i < 4; i++){
            cout << ptr_array[i] << " ";
        }
        cout << endl;
        // 2 2 3 4
        for(int i = 0; i < 4; i++){
            cout << ptr_array1[i] << " ";
        }
        cout << endl;
        
        
        cout << endl;
        const int c_val = 111;
        int& use_val = const_cast<int&>(c_val); // 去常量的引用
        int* ptr_val = const_cast<int*>(&c_val); // 去常量的指针
        // vs2017 111 111 111
        cout << c_val << " " << use_val << " " << *ptr_val << endl;
        use_val = 222; // 未定义行为
        // vs2017 111 222 222
        cout << c_val << " " << use_val << " " << *ptr_val << endl;
        *ptr_val = 333; // 未定义行为
        // vs2017 111 333 333
        cout << c_val << " " << use_val << " " << *ptr_val << endl;
        // 未定义行为：C++标准暂未对此类行为给出明确规定
        // 值修改后，c_val\use_val\ptr_val三者地址相同，但目前c_val保持原有值，后续可能有变
        
        // reinterpret_cast =====================
        cout << endl;
        int * ptr = new int(100);
        float * ptr1 = reinterpret_cast<float*>(ptr);
        uint * ptr2 = reinterpret_cast<uint*>(ptr);
        // 三者指针地址相同，ptr2和ptr的值相同，ptr1的值改变了
        cout << "ptr:" << ptr << " " << *ptr <<endl;
        cout << "ptr1:" << ptr1 << " " << *ptr1 << endl;
        cout << "ptr2:" << ptr2 << " " << *ptr2 << endl;
        

    } catch (exception& e) {cout << "Exception: " << e.what();}
    return 0;
}
