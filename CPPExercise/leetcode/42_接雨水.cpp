//
//  42_接雨水.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/8/29.
//
/**
 12
 0 1 0 2 1 0 1 3  2 1 2 1
 */

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define N 20010

class Solution {
public:
    // 按行求，会超时
    int trap_row(vector<int>& height) {
        int maxH = *max_element(height.begin(), height.end());
        int res = 0;
        for(int i = 1; i <= maxH; i++){
            int tmp = -1;
            for(int j = 0; j < height.size(); j++){
                if(height[j] < i){
                    if(tmp != -1){
                        tmp++;
                    }
                } else {
                    if(tmp != -1){
                        res += tmp;
                    }
                    tmp = 0;
                }
            }
        }
        return res;

    }
    
    // 按列求，动规
    int maxL[N];
    int maxR[N];
    int trap_col(vector<int>& height) {
        if(height.size() < 3){
            return 0;
        }
        memset(maxL, 0, sizeof(maxL));
        memset(maxR, 0, sizeof(maxR));
        for(int i = 1; i < height.size() - 1; i++){
            maxL[i] = max(maxL[i - 1], height[i - 1]);
        }
        for(int i = height.size() - 2; i >= 0; i--){
            maxR[i] = max(maxR[i + 1], height[i + 1]);
        }
        int res = 0;
        for(int i = 1; i < height.size() - 1; i++){
            if(height[i] < maxL[i] && height[i] < maxR[i]){
                res += (min(maxL[i], maxR[i]) - height[i]);
            }
        }
        return res;
    }
    
    // 双指针做法 O1空间，On时间
    int trap_ptr(vector<int>& height) {
        if(height.size() < 3){
            return 0;
        }
        int max_left = height[0];
        int max_right = height[height.size()- 1];
        int left = 1;
        int right = height.size() - 2;
        int res = 0;
        while(left <= right){
            if(max_left <= max_right){
                if(height[left] < max_left){
                    res += max_left - height[left];
                }
                left++;
                max_left = max(max_left, height[left - 1]);
                
            } else {
                if(height[right] < max_right){
                    res += max_right - height[right];
                }
                right--;
                max_right = max(max_right, height[right + 1]);
                
            }
        }
        return res;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0;i < n; i++){
        cin >> nums[i];
    }
     cout << Solution().trap_ptr(nums) << endl;
    return 0;
}
