//
//  剑指offer43_连续子数组的最大和.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/8/20.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        int maxSum = nums[0];
        int curSum = nums[0];
        for(int i = 1; i < nums.size(); i++){
            curSum = max(curSum + nums[i], nums[i]);
            maxSum = max(curSum, maxSum);
        }
        return maxSum;
    }
};
