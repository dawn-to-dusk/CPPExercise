//
//  剑指offer47_礼物的最大价值.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/8/20.
//

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 0){
            return 0;
        }
        int m = grid[0].size();
        vector<vector<int>> sum(n+1, vector(m+1, 0));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                sum[i][j] = grid[i-1][j-1] + max(sum[i-1][j], sum[i][j-1]);
            }
        }
        return sum[n][m];
    }
};
