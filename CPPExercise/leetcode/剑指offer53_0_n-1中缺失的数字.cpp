//
//  剑指offer53_0_n-1中缺失的数字.cpp
//  Tmp
//
//  Created by Baozhu Fang on 2022/8/13.
//

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int left, int right){
        if(left >= right){
            if(nums[right] != right){
                return right;
            }
            return nums.size();
        }
        
        int mid = (left + right) >> 1;
        if(nums[mid] == mid){
            return search(nums, mid + 1, right);
        } else {
            return search(nums, left, mid);
        }
    }
    int missingNumber(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        return search(nums, 0, nums.size() - 1);
    }
};

int main(){
    int n ;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    Solution sol;
    cout << sol.missingNumber(nums) << endl;
}
