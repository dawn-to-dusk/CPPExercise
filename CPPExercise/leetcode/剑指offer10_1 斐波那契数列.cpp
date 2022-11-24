//
//  剑指offer10_1 斐波那契数列.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/8/20.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int nums[110];
    Solution(){
        memset(nums, -1, sizeof(nums));
    }
    int fib(int n) {
        if(nums[n] != -1){
            return nums[n];
        }
        if(n == 0){
            nums[n] = 0;
        } else if(n == 1){
            nums[n] = 1;
        } else {
            nums[n] = (fib(n-1) % 1000000007 + fib(n-2) % 1000000007) % 1000000007;
        }
        return nums[n];
    }
};
