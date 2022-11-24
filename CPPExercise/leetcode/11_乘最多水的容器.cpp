//
//  11_乘最多水的容器.cpp
//  CPPExercise
//  双指针，每次移动小的指针
//  Created by Baozhu Fang on 2022/8/24.
//

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int sum = min(height[left], height[right]) * (right - left );
        while(left != right) {
            if(height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
            sum = max(sum, min(height[left], height[right]) * (right - left ));
        }

        return sum;
    }
};
