//
//  线性dp-最长上升子序列-优化-acwing896.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/9/12.
//

/*
 当数据量较大时，n^可能超时
 
 可以对状态计算的过程优化
 用一个数组存储每个长度的最小尾数，拿到一个新的数，直接去找小于当前数的最大长度尾数即可
 
 1≤N≤100000，
 −109≤数列中的数≤109
 
 7
 3 1 2 1 8 5 6

 4
 */
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100010;
int n;
int dp[N];
int len[N];



