//
//  1_计算平均年龄.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/8/27.
//

/**
 已知某公司总人数为W，平均年龄为Y岁(每年3月末计算，同时每年3月初入职新人)，假设每年离职率为x，x>0&&x<1,每年保持所有员工总数不变进行招聘，新员工平均年龄21岁。 从今年3月末开始，请实现一个算法，可以计算出第N年后公司员工的平均年龄。(最后结果向上取整)。

 */


#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int main(){
    float Y;
    int W, N;
    float x;
    cin >> W >> Y >> x >> N;
    while(N-- != 0){
        int oldSum = (1 - x) * (Y + 1) * W;
        int newSum = x * W * 21;
        Y = (oldSum + newSum) / W;
    }

    cout << ceil(Y) << endl;
    return 0;
}

