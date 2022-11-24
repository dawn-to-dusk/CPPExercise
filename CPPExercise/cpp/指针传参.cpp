//
//  指针传参.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/9/11.
//

#include<iostream>
using namespace std;

void func(int *p, int *q){
    *p++;
    *q=*q+1;
}

int main(){
    int a = 1, b = 1, *p = &a;
    
    // p是指针传参，不改变
    // b是引用传参，改变
    func(p, &b);
    
    cout << a << " " << b; // 1 2
    return 0;
}
