//
//  位运算-64位整数乘法acwing90.cpp
//  CPPExercise
//
//  a * b % p
//  类似快速幂思想，将乘法转换为加法
//
//  Created by Baozhu Fang on 2022/7/29.
//

#include <stdio.h>
#include <iostream>
using namespace std;

long long a, b, p;

int main(){
    cin >> a >> b >> p;
    long long res = 0;
    while(b){
        if(b&1){
            res = (res + a) % p;
        }
        a = (a + a) % p;
        b = b >> 1;
    }
    
    cout << res << endl;
}
