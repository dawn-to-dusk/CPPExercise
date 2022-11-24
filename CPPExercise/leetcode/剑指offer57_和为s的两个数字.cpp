//
//  剑指offer57_和为s的两个数字.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/8/31.
//

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while(l < r){
            while (nums[l] + nums[r] >= target){
                if(nums[l] + nums[r] == target){
                    return vector<int> {nums[l], nums[r]};
                }
                r--;
            }
            while(nums[l] + nums[r] <= target){
                if(nums[l] + nums[r] == target){
                    return vector<int> {nums[l], nums[r]};
                }
                l++;
            }
        }
        return vector<int> {-1, -1};
    }
};
