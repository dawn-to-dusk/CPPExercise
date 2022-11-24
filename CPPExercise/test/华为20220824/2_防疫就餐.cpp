/**
 受疫情影响，员工到食堂吃饭需要隔位就坐，也就是前后左右相邻两个位署不能同时坐人。假设食堂座位按长方形网格排列，部分座位上已经坐了人，就坐的人符合隔位就餐限制。问在满足隔位就餐限制下最多还能容纳的就餐人数。
 
 输入n、m代表矩阵长宽。然后输入m行，每行n个数字。0表示空位，1代表有人就坐。
 1<=m,n<=20
 输出在当前限制条件下，最多还能容纳的就餐人数
 
 示例1
 input
 2 4
 1 0 0 0
 0 0 0 1
 output
 2
 
 示例2
 input:
 4 6
 1 0 0 0 0 1
 0 0 0 0 0 0
 0 1 0 0 0 1
 0 0 0 0 0 0
 output:
 7
 
 */


/*
 预处理好所有可行策略，某一条策略可应用的条件：
 - 与当前行已经坐了人的不重合
 - 与上一行已经坐了人的不重合
 - 应用在当前行后的结果是一种可行策略
 */


#include<iostream>
#include<vector>
#include<bitset>
#include<string.h>
#include<unordered_map>
using namespace std;

int m;
int n;
vector<vector<int>> matrixTmp; // 原始矩阵
vector<int> matrix; // 原始状压矩阵
unordered_map<int, int> valid;// 所有可行策略，策略->做的人数


// i是matrix中的序号，当前策略是matrix[i]
// pre上一行的策略
int fun(int i, int pre){
    if(i == m){
        return 0;
    }
    
    int cur = matrix[i];
    // 有重合，不可以
    if(cur & pre != 0){
        return 0;
    }
    
    // 没有重合
    int res = 0;
    // 遍历可行策略，看当前用哪一个
    for(auto [v, c] : valid){
        // 当前策略不能和当前已坐情况重合，即坐过的地方不能坐
        if(v & cur != 0){
            continue;
        }
        // 当前策略不能和上一行重合，即上下相邻不能坐
        if(v & pre != 0){
            continue;
        }
        // v | cur 即将v策略用到当前行，如果在valid中，即是可行的
        // 在当前行可行的情况下，个数为：当前行个数 + 基于当前行的下一行个数
        if(valid.find(v | cur) != valid.end()){
            res = max(res, c + fun(i + 1, v|cur));
        }
    }
    return res;
}


int main(){
    cin >> m >> n;
    matrixTmp.resize(m);
    for(int i = 0; i < m; i++){
        matrixTmp[i].resize(n);
        for(int j = 0; j < n; j++){
            cin >> matrixTmp[i][j];
        }
    }
    
    // 将矩阵转换为多个二进制数字
    for(int i = 0; i < m; i++){
        int v = 0;
        for(int j = 0; j < n; j++){
            v = (v<<1) | matrixTmp[i][j];
        }
        //每个v是一个数字，如1 0 0 0 转换为1000
        matrix.push_back(v);
    }
    
    // 初始化基于原始矩阵规格的所有可行策略（只要没有相邻11都可以）
    // 最大值为1<<n-1，比如列数为3就是1000 - 1 = 111
    // 遍历所有情况，找出没有11相邻的
    for(int i = 0; i < (1 << n); i++){
        bitset<20> bs(i);
        string str = bs.to_string();
        if(str.find("11") != string::npos){ // 有相邻不要
            continue;
        }
        valid[i] = count(str.begin(), str.end(), '1');
    }
    
    // 递归查matrix
    cout << fun(0, 0) << endl;
    return 0;
}
