//
//  位运算-最短哈密顿路径.cpp
//  CPPExercise
//
//  旅行商问题 np完全问题
//
//  动态规划数组：
// （1）当前遍历过哪些点
// （2）当前终点是哪个点
// f[state][j] = f[state_k][k] + weight[k][j]
//  state = state_k U j, state_k中一定包含k
//
//  状态压缩：如何表示state
//  题目中共有20个点，可以用二进制位来表示20个点集合的状态
//
//  memeset
//  - 头文件：cstring
//  - memset(f, 0x3f, sizeof f) //给f数组每一位赋值无穷大，f是int数组，如果f是float，用0x4f
//
//  Created by Baozhu Fang on 2022/8/1.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

// 总点数
int n;
// state的个数和j的个数
const int N = 1 << 20, M = 20;

int f[N][M], weight[M][M];

int main() {
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> weight[i][j];
        }
    }
    memset(f, 0x3f, sizeof f);
    f[1][0] = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            // 判断当前state是否符合题目要求，即i集合中一定包含j
            if(i >> j & 1){
                for(int k = 0; k < M; k++){
                    // 判断当前的state_k是否符合条件
                    if(i - (1 << j) >> k & 1){
                        f[i][j] = min(f[i - (1 << j)][k] + weight[k][j], f[i][j]);
                    }
                }
            }
        }
    }
    
    cout << f[(1 << n) - 1][n - 1] << endl;
    return 0;
}
