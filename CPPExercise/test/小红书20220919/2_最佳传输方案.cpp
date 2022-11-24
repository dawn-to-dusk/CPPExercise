//
//  2_最佳传输方案.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/9/19.
//

/*
 现在你位于连绵的峰峦之间。你的任务是从1号山峰抵达n号山峰。
 你拥有一个传送门可以将你送往后续距离不超过k的山峰中。举例，当k=2时，若你在山峰7，则你可以传送至山峰2或山峰3。这里距离的定义为感号的差值。
 使用传送门需要付出金币。付出的规则如下:若当前在山峰u，将要去往的是山峰v，当山峰 u的高度高于山峰v时，不需要付出金币;否则，当山峰u的高度低于山峰v时，需要付出(山峰v的高度-山峰u的高度)这么多的金币。举例如下:
 当前在山峰1，高度为5，若传送至山峰2，高度为4，因为5>4，本次不花费金币;
 当前在山峰1，高度为5，若传送至山峰3，高度为6，因为6>5，本次花费(6-5=1)的金币。

 你的任务是从1号山峰恰好传送至n号山峰，询问你最少要花费的金币数量。
 输入描述
 第一行两个正整数n和k，分别表示山峰有n个，每次传送的距离不超过k接下来一行n个正整数，分别表示每座山峰的高度
 输出米哦啊数
 一行一个非负整数，表示最少要花费的金币数量
 
 5 2
 1 5 3 4 2
 2
 样例解释1
 最小的方案是从位置1跳到位置3再跳到位置5。第一次跳跃花费两枚金币，第二次不花费金币。容易看出不存在更小的方案。
 1 <= n <= 2000, 1 <= k <= 1000山峰高度保证是[1，100]之间的正整数。
 */

// ak


#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
const int N = 2010;
int n, k;
int nums[N];
int dp[N][N];

int gas(int a, int b){
    if(nums[a] >= nums[b]){
        return 0;
    } else {
        return nums[b] - nums[a];
    }
}

void func(int a, int b){
    if(b - a <= k){
        dp[a][b] = gas(a, b);
    } else {
        for(int i = b-k; i < b; i++){
            dp[a][b] = min(dp[a][b], dp[a][i] + gas(i, b));
        }
    }
}


int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> nums[i];
    }
    
    memset(dp, 0x3f, sizeof(dp));
    for(int i = 1; i < n; i++){
        for(int j = 2; j <= n; j++){
            func(i, j);
        }
    }
    
    cout << dp[1][n] << endl;
    return 0;
}
