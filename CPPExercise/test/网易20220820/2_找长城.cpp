//
//  2_找长城.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/8/20.
//

/**
嘤嘤觉得长城很美 ，特别是它的锯齿， 非常的优雅！
 现在有一个数组，嘤嘤想把这个数组变成"长城"，即对于"长城"中每 一个元 素左右两边的元素相等，并且与它不相等。例如[2，1，2，1，2，1，2），（1，9，1，9}是长城，{2，1，3，2，4，1，4，4，4，4）则不是长城。
 你每次可以将一个元素加一，请问最少需要几次操作？

 输入n和n个正整数。其中n<=2e5，ai<=1e9。
 
 input:
 6
 1 1 4 5 1 4
  
 output:
 11
 */

/**
 注意longlong
 */

#include<iostream>
#include<algorithm>
#include<vector>
#include<stdlib.h>
using namespace std;


long long getNum(vector<long long> nums){
    if(nums.size() <= 2){
        return 0;
    }
    if(nums.size() == 3){
        if(nums[0] == nums[1] && nums[0] == nums[2]){
            return 1;
        } else {
            return abs(nums[0] - nums[nums.size() - 1]);
        }

    }

    // a表示奇数索引
    // b表示偶数索引
    long long aMax = 0, bMax = 0;
    long long sum = 0;
    for(int i = 0; i < nums.size(); i++){
        if(i % 2 == 0){
            bMax = max(bMax, nums[i]);
        } else {
            aMax = max(aMax, nums[i]);
        }
        sum += nums[i];
    }
    // 奇数索引个数
    long long aL = nums.size() / 2;
    long long bL = nums.size() - aL;
    if(aMax != bMax){
        return aL * aMax - sum + bL * bMax;
    } else {
        long long res1 = aL * aMax  - sum + bL * (bMax+1);
        long long res2 = aL * (aMax+1)  - sum + bL * bMax;
        return res1 > res2 ? res2 : res1;
    }
}

int main(){
    int n;
    cin >> n;
    vector<long long> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    cout << getNum(nums) << endl;
    return 0;
}
