//
//  剑指offer03_数组中重复的数字.cpp
//  Tmp
//
// 大数可以用哈希map或者bitmap
//  Created by Baozhu Fang on 2022/8/13.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        // map<int, int> numM;
        // for(int i = 0; i < nums.size(); i++){
        //     if(numM.find(nums[i]) != numM.end()){
        //         return nums[i];
        //     }
        //     numM[nums[i]] = 1;
        // }
        // 用数组比vector更快
        int a[100001];
        memset(a, 0, sizeof(a));
        for(int i = 0; i < nums.size(); i++){
            if(a[nums[i]] == 1){
                return nums[i];
            }
            a[nums[i]]++;
        }
        return 0;
    }
};


int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    
    Solution sol;
    cout << sol.findRepeatNumber(nums) << endl;
}
