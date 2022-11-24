//
//  剑指offer_II_098_路径的数目.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/9/3.
//

#include<iostream>
using namespace std;


class Solution {
public:
    int n, m;
    int ways[102][102];
    int getWays(int i, int j){
        if(i >= n || j >= m || i < 0 || j < 0){
            return 0;
        }

        if(ways[i][j] == 0){
            if(i == 0 && j == 0){
                ways[i][j] = 1;
            } else {
                ways[i][j] = getWays(i - 1, j) + getWays(i, j - 1);
            }
        }
        return ways[i][j];
    }
    
    int uniquePaths(int m, int n) {
        this->n = m;
        this->m = n;
        return getWays(m - 1, n - 1);
    }
};

