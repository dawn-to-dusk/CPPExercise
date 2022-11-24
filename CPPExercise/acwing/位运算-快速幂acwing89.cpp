//
//  位运算-快速幂acwing89.cpp
//  CPPExercise
//
//  快速幂的思想，a^b可以等价为多个a的乘方因子，其中每个乘方为b转换为二进制后为1的位
//  e.g. 3^7(111)=3^1 * 3^2(10) * 3^4(100)
//
//  Created by Baozhu Fang on 2022/7/29.
//

#include <stdio.h>
#include <iostream>
using namespace std;

int a, b, p;

int main(){
    cin >> a >> b >> p;
    int res = 1 % p;
    while(b){
        if(b & 1)
            res = res * 1ll * a % p;
        a = a * 1ll * a;
        b= b>>1;
    }
    
    cout << res << endl;
}
