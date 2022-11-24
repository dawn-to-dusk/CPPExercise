//
//  221_最大正方形.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/9/11.
//

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size() <= 0) return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> len(n, vector<int>(m));
        int maxL = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == '1'){
                    if(i == 0 || j == 0){
                        len[i][j] = 1;
                    } else {
                        len[i][j] = min(min(len[i-1][j-1], len[i-1][j]), len[i][j-1]) + 1;
                    }
                    maxL = max(maxL, len[i][j]);
                }
            }
        }
        return maxL * maxL;
    }
};
