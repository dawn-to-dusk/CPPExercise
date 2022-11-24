//
//  剑指offer46_把数字翻译成字符串.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/8/20.
//

#include<iostream>
using namespace std;

class Solution {
public:
    int translateNum(int num) {
        int pre = num %10;
        int cur = 0;
        int pCount = 1;
        int ppCount = 1;
        int curCount = 1;
        num = num/10;
        while(num != 0){
            cur = num % 10;
            if(cur == 0 || cur * 10 + pre > 25){
                curCount = pCount;
            } else {
                curCount = pCount + ppCount;
            }
            ppCount = pCount;
            pCount = curCount;
            pre = cur;
            num = num / 10;
        }
        return curCount;
    }
};
