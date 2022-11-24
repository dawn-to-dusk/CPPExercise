//
//  线性dp-最长上升子序列-acwing895.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/9/12.
//

/*
 状态表示：dp[i]表示以i结尾的最长上升子序列长度
 
 状态计算：
 dp[i] = max(dp[j], j为0～i-1且符合num[j] < num[i]) + 1
 */

/*
 7
 3 1 2 1 8 5 6
 
 4
 
 1≤N≤1000，
 −109≤数列中的数≤109
 */

#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

const int N = 1010;
int n;
int dp[N];
int num[N];

int main(){
    int n;
    cin >> n;
    int res = 0;
    for(int i = 0;i < n; i++){
        dp[i] = 1;
        cin >> num[i];
        for(int j = 0; j < i; j++){
            if(num[j] < num[i])
                dp[i] = max(dp[j] + 1, dp[i]);
        }
        res = max(dp[i], res);
    }
    
    cout << res << endl;
    return 0;
}
