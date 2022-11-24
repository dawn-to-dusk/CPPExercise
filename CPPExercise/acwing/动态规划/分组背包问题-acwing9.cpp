//
//  分组背包问题-acwing9.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/9/12.
//

/*
 相当于多重背包问题（多重背包是分组背包的特例）
 每一组中只能选一个，只能用三重循环，没有优化
 */

/*
 3 5
 2
 1 2
 2 4
 1
 3 4
 1
 4 5
 
 8
 */

#include<iostream>
#include<algorithm>
using namespace std;

const int N = 110;
int n, m;
int dp[N];
int v[N];
int w[N];

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int s;
        cin >> s;
        for(int j = 0; j < s; j++) cin >> v[j] >> w[j];

        for(int j = m; j >= 0; j--){
            for(int k = 0; k < s; k++){
                if(v[k] <= j) // 注意这个判断条件不能放在for循环中，因为这不是循环停止的标志，组内商品数量体积不一定有序
                    dp[j] = max(dp[j], dp[j-v[k]] + w[k]);
            }
        }
    }
    
    cout << dp[m] << endl;
    return 0;
}
