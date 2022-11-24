//
//  多重背包问题-acwing4.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/9/12.
//

/*
 暴力解法
 01背包扩展  三层循环
 */

/*
 4 5
 1 2 3
 2 4 1
 3 4 3
 4 5 2
 
 10
 */

#include<iostream>
#include<algorithm>
using namespace std;
const int N = 110;
int n, m;
int dp[N];

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        int v, w, s;
        cin >> v >> w >> s;
        for(int j = m; j >= 0; j--){
            for(int k = 1; k <= s && k * v <= j; k++){
                dp[j] = max(dp[j], dp[j-k*v] + k * w);
            }
        }
    }
    
    cout << dp[m] << endl;
    return 0;
}
