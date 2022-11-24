//
//  区间合并-acwing803.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/7/29.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
typedef pair<int, int> PII;
vector<PII> segs;

void merge(vector<PII> &segs){
    vector<PII> res;
    // 上一个区间的始终
    int st = -2e9, ed = -2e9;
    for(auto item: segs){
        if(item.first <= ed){
            // 有重合，需要合并
            ed = max(ed, item.second);
        } else {
            if(ed != -2e9){
                // 与上一个区间无重合，将上一个区间回收
                res.push_back({st, ed});
            }
            // 新区间是一个新区间
            st = item.first;
            ed = item.second;
        }
    }
    if(ed != -2e9) {
        res.push_back({st, ed});
    }
    
    segs = res;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        segs.push_back({l,r});
    }
    
    // 排序
    sort(segs.begin(), segs.end());
    
    // 合并
    merge(segs);
    
    cout << segs.size() << endl;
    return 0;
}
