//
//  剑指offer10_II 青蛙跳台阶问题.cpp
//  CPPExercise
//  斐波那契数列问题
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
    int numWays(int n) {
        if(nums[n] == -1){
            if(n == 0){
                nums[n] = 1;
            } else if(n == 1){
                nums[n] = 1;
            } else {
                nums[n] = (numWays(n-1) % 1000000007 + numWays(n-2) % 1000000007) % 1000000007;
            }
        }
        return nums[n];

    }
};
