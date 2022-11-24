//
//  1_分子分母求和.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/8/20.
//

/**
 输入n，求前n个分数之和，结果保留两位小数
 第一个分数是1/2，后面每个分数的分母是前一个分数的分子加分母，分子是前一个分数的分母
 输入2，输出1.17
 */
#include<iostream>
#include<cmath>
#include<vector>
#include<map>
using namespace std;

int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}

float getRes(int n){
    int up = 1.0;
    int  down = 2.0;
    int  uSum = 1;
    int  dSum = 2;
    for(int i = 1; i < n;i++){
        int tmp = down;
        down = up + down;
        up = tmp;
        uSum = uSum * down + dSum * up;
        dSum = dSum * down;
        int gcdN = gcd(uSum, dSum);
        uSum = uSum / gcdN;
        dSum = dSum / gcdN;
    }

    int res =uSum * 1000/dSum;
    int last = res % 10;
    if(last >= 5){
        res = res - last + 10;
    } else {
        res = res - last;
    }
    return float(res)/1000;
}

int main(){
    int n;
    cin >> n;

    cout << getRes(n) << endl;
}
