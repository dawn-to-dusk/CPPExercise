//
//  线性dp-数字三角形-acwing898.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/9/12.
//

/*
 闫式dp分析法
 
 状态表示：
 - 表示某个集合：dp通过一次处理一类集合来简化问题，具体用什么来表示根据经验
    - 线性问题一般用坐标
 - 表示集合的某个状态：最大值？最小值？个数？——求的是什么就是什么属性
 
 状态计算：
 状态转移公式，对应集合划分，选择某个集合
 
 */

/*
 如果从上向下分析，每个节点可能来着上面的左节点或右节点，边界节点需要特殊分析
 如果从下向上分析，每个节点都有左右节点无需特殊处理，故选择从下向上分析
 */

/*
 5
 7
 3 8
 8 1 0
 2 7 4 4
 4 5 2 6 5
 
 30
 
 1≤n≤500,
 −10000≤三角形中的整数≤10000
 */

#include<iostream>
#include<algorithm>
using namespace std;

const int N = 510;
int n;
int dp[N][N];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            cin >> dp[i][j];
        }
    }
    
    for(int i = n-2; i >= 0; i--){
        for(int j = 0; j <= i+1; j++){
            dp[i][j] = dp[i][j] + max(dp[i+1][j], dp[i+1][j+1]);
        }
    }
    
    cout << dp[0][0] << endl;
    return 0;
}
