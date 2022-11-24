//
//  154_寻找旋转排序数组中的最小值II.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/9/20.
//

#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        while(left < right){
            int mid = (left + right) >> 1;
            if(nums[mid] < nums[right]){
                right = mid;
            } else if(nums[mid] > nums[right]){
                left = mid + 1;
            } else {
                            right--;
            }
        }

        return nums[left];
    }
};


int main(){
    vector<int> nums = {5, 6, 7, 1, 2, 3, 4};
    cout << Solution().findMin(nums) << endl;;
    return 0;
}
