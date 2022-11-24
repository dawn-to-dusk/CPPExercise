//
//  函数指针.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/8/8.
//

#include <stdio.h>
#include <iostream>
using namespace std;

int foo(){
    return 5;
}

int main(){
    cout << foo << endl;
    cout << foo() << endl;
    int (*fptr)() = foo;
    cout << fptr() << endl;
    return 0;
}
