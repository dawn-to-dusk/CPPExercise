//
//  1518_换酒问题.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/8/29.
//

#include<iostream>
using namespace std;

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res = numBottles;
        while(numBottles >= numExchange){
            numBottles -= numExchange;
            numBottles++;
            res++;
        }
        return res;
    }
};
