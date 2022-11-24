//
//  189_轮转数组.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/9/20.
//

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void reverse(vector<int> &nums, int start, int end){
        while(start < end){
            swap(nums[start++], nums[end--]);
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        reverse(nums, 0, n-1);
        reverse(nums, 0, k-1);
        reverse(nums, k, n-1);
    }
};

int main(){
    vector<int> nums = {1,2,3,4,5,6,7};
    int k = 3;
    Solution().rotate(nums, k);
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }
}
