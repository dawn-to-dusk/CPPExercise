//
//  面试题01_07_旋转矩阵.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/9/1.
//

#include<iostream>
#include<vector>
using namespace std;
/*
 i, j
 j, n - i - 1
 n - i - 1, n - j - 1
 n - j - 1, i
 */

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int x = n % 2 == 0 ? n / 2 : n / 2 + 1;
        int y = n / 2;
        for(int i = 0; i < x; i++){
            for(int j = 0; j < y; j++){
                swap(matrix[i][j], matrix[j][n - i - 1]);
                swap(matrix[i][j], matrix[n - i - 1][n - j - 1]);
                swap(matrix[i][j], matrix[n - j - 1][i]);
            }
        }
    }
};
