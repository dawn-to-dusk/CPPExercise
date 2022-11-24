//
//  剑指offer53_在排序数组中找到数字.cpp
//  Tmp
//
//  Created by Baozhu Fang on 2022/8/13.
//

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int searchNum(vector<int>& nums, int target, int left, int right){
        if(left >= right){
            if(nums[left] == target){
                return left;
            }
            return -1;
        }
        
        int mid = (left + right) >> 1;
        if(nums[mid] < target){
            return searchNum(nums, target, mid + 1, right);
        } else {
            return searchNum(nums, target, left, mid);
        }
    }
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0){
            return 0;
        }
        int pos = searchNum(nums, target, 0, nums.size() - 1);
        if(pos == -1){
            return 0;
        }
        int count = 0;
        while(pos < nums.size() && nums[pos] == target){
            count++;
            pos++;
        }
        return count;
    }
};

int main(){
    int n, t;
    cin >> n >> t;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    
    Solution sol;
    cout << sol.search(nums, t) << endl;
}
