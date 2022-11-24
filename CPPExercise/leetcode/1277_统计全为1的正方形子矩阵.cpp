//
//  1277_统计全为1的正方形子矩阵.cpp
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
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n <= 0){
            return 0;
        }
        int m = matrix[0].size();
        vector<vector<int>> len(n, vector<int>(m));

        int cnt = 0;
        for(int i = 0;i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 1){
                    if(i == 0 || j == 0){
                        len[i][j] = 1;
                    } else {
                        len[i][j] = min(min(len[i-1][j], len[i][j-1]), len[i-1][j-1]) + 1;
                    }
                    cnt += len[i][j];
                }
            }
        }
        return cnt;
    }
};
