//
//  离散化-区间和acwing802.cpp
//  CPPExercise
//  1.序列去重
//    vector<int> alls;
//    sort(alls.begin(), alls.end());
//    alls.erase(unique(all.begin(), all.end()), all.end()); // 去重
//  2.快速映射：找到x对应离散化后的数组下标（二分）
//
//  本题涉及知识点：前缀和、二分查找、vector排序去重
//
//  Created by Baozhu Fang on 2022/7/29.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 设置为3w是因为add里面有n个坐标，query里面有2m个坐标，加起来就是3倍的1w
const int N = 300010;
typedef pair<int, int> PII;

int n, m;
vector<PII> add;
// 查询操作
vector<PII> query;
// 所有元素的原下标
vector<int> all;
// 映射后的数组 前缀和数组
int a[N], s[N];

// 找到all中值为val的元素在all中的下标，val是离散化前的坐标，返回值是离散化后的坐标
int find(vector<int> all, int val){
    int l = 0, r = all.size()-1;
    
    // 本题中val应该是一定能找到的，可以不需要哨兵
    while(l < r){
        int mid = (l + r) >> 1;
        if(all[mid] >= val){
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    
    // 为了方便前缀和，下标从1开始
    return r + 1;
}

int main(){
    cin >> n >> m;
    // 插入操作

    for(int i = 0;i < n; i++){
        int x, c;
        cin >> x >> c;
        add.push_back({x, c});
        all.push_back(x);
    }
    for(int i = 0;i < m; i++){
        int l, r;
        cin >> l >> r;
        query.push_back({l, r});
        all.push_back(l);
        all.push_back(r);
    }
    
    // all排序去重
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    
    // 处理插入操作
    for(auto item: add){
        // 原坐标item.first映射到新坐标x（x从1开始）
        int x = find(all, item.first);
        a[x] += item.second;
    }
    
    // 处理前缀和
    for(int i = 1; i <= all.size(); i++){
        s[i] = s[i-1] + a[i];
    }
    
    // 处理查询
    for(auto item: query){
        int l = find(all, item.first), r = find(all, item.second);
        cout << s[r] - s[l-1] << endl;
    }
    
    return 0;
    
}
