//
//  2_路径.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/8/31.
//

/*
 现在有一个n行m列的网格图。每个格子上有一个数字，为 +k 或者 -k。
 初始你在位于左上方的第一行第一列，你的目标是走到位于右下方的第n行第m列。
 现在限制你每一步只能向下或者向右走。显然，你有很多种实现目标的方法。现在，我们定义路径的权值和为你选定的路径上所有格子上的数字的加和。我们的问题是，你能否选出一条合适的路径，使得你获得恰好为x的权值和。1 <= n, m <= 10
 对全体数据保证:1<=T<= 5,0 <= k <= 10,0 <= x <= 1000000
 
 输入描述
 第一行一个正整数T，表示总共有T组数据。对于每组数据:
 第一行给出四个自然数n，m，k，x，以空格分开，表示给出的网格图是 n行m列的，其中仅有+k和-k两种数字，所希望你获得的权值和为X。
 接下来将依次给出n行，每行m个整数，表示网格中的数字。
 输出描述
 对每一组数据输出一行yes或no表示答案，共输出T行。
 
 input:
 3
 2 4 1 2
 -1 -1 1 -1
 -1 -1 -1 -1
 1 2 1 1
 1 -1
 1 3 9 9
 9 -9 9
 output:
 no
 no
 yes
 */


#include<iostream>
#include<vector>
using namespace std;

int n, m, k, x;

bool dfs(vector<vector<int>> nums, int i, int j, int cur){
    if(i >= n || j >= m){
        return false;
    }
    if(i == n - 1 && j == m - 1){
        if(cur + nums[i][j] == x){
            return true;
        } else {
            return false;
        }
    }
    
    if(dfs(nums, i + 1, j, cur + nums[i][j])){
        return true;
    } else if(dfs(nums, i, j + 1, cur + nums[i][j])){
        return true;
    } else {
        return false;
    }
}

bool check(vector<vector<int>> nums){
    if(x % k != 0){
        return false;
    }
    
    if(dfs(nums, 0, 0, 0)){
        return true;
    } else {
        return false;
    }
}

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n >> m >> k >> x;
        vector<vector<int>> nums(n, vector<int>(m));
        for(int i = 0; i <n; i++){
            for(int j = 0; j < m; j++){
                cin >> nums[i][j];
            }
        }
        
        if(check(nums)) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
    
    
}
