//
//  剑指offer63_股票的最大利润.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/8/20.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/**
 用一个参数记录历史最低股票
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) {
            return 0;
        }
        int minPrice = prices[0];
        int res = 0;
        for(int i = 1; i < prices.size(); i++){
            minPrice = min(minPrice, prices[i]);
            res = max(res, prices[i] - minPrice);
        }
        return res;
    }
};
