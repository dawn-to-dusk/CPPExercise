//
//  贪心-区间选点.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/8/2.
//

/*
 双指针做法
 */

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
typedef pair<int, int> PII;
vector<PII> segs, adds;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        segs.push_back(PII{x, y});
    }
    
    sort(segs.begin(), segs.end());
    int l = segs[0].first, r = segs[0].second;
    for(auto item:segs){
        if(item.first > r) {
            // 不合并
            adds.push_back(PII{l, r});
            l = item.first;
            r = item.second;
        } else {
            // 合并
            r = max(item.second, r);
        }
    }
    adds.push_back(PII{l, r});
    cout << adds.size() << endl;
    
    return 0;
}
