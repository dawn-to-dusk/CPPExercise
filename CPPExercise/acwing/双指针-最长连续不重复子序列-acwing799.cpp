//
//  双指针-最长连续不重复子序列-acwing799.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/7/28.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

const int N = 100010;

// 原数组的数值范围不大，可以直接用数组来做
int main() {
    int n;
    cin >> n;
    int S[N], nums[N];
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    
    int res = 0;
    for(int i = 0, j = 0; i < n; i++){
        S[nums[i]]++;
        while(S[nums[i]] > 1){
            S[nums[j++]]--;
        }
        res = max(res, i-j+1);
    }
    
    cout << res << endl;
    return 0;
}

//// map的做法
//int main(){
//    int n;
//    cin >> n;
//    vector<int> nums(n);
//    for(int i = 0; i < n; i++){
//        cin >> nums[i];
//    }
//
//    int x = 0, y = 0, max = 0;
//    map<int, int> nMap;
//    for(int i = 0; i < n; i++){
//        if (nMap.find(nums[i]) != nMap.end()){
//            // 重复
//            if(y - x > max){
//                max = y - x;
//            }
//            for (int j = x; j < nMap[nums[i]]; j++){
//                nMap.erase(nums[j]);
//            }
//            x = nMap[nums[i]] + 1;
//        }
//        nMap[nums[i]] = i;
//        y++;
//    }
//    if(y - x > max){
//        max = y - x;
//    }
//
//    cout << max << endl;
//    return 0;
//}
