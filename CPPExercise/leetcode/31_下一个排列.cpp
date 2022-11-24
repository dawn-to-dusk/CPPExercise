//
//  31_下一个排列.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/8/29.
//

#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
//    void reverse(vector<int> &nums, int x){
//        int y = nums.size() - 1;
//        while(x < y){
//            swap(nums[x++], nums[y--]);
//        }
//    }
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while(i >= 0 && nums[i] >= nums[i+1]){
            i--;
        }
        if(i >= 0){
            int j = nums.size() - 1;
            for(; j > i; j--){
                if(nums[j] > nums[i]){
                    break;
                }
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    Solution().nextPermutation(nums);
    for(int i = 0;i < n; i++){
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}
