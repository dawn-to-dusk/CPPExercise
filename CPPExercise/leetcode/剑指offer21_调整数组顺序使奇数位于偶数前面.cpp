//
//  剑指offer21_调整数组顺序使奇数位于偶数前面.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/8/31.
//

#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        while(l < r){
            while(l <= nums.size() - 1 && nums[l] % 2 != 0){
                l++;
            }
            while(r >= 0 && nums[r] % 2 == 0){
                r--;
            }
            if(l <= nums.size() - 1 && r >= 0 && l < r){
                swap(nums[l], nums[r]);
            }
        }
        return nums;
    }
};
