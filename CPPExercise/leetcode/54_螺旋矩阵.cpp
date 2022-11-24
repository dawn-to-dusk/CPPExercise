//
//  54_螺旋矩阵.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/8/12.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> res;
    int x, y;
    int left, right, top, bottom;

    void pushNum(int x, int y, vector<vector<int>>& matrix){
        if(x >= top && x <= bottom && y >= left && y <= right){
            res.push_back(matrix[x][y]);
        }
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        left = -1;
        right = matrix[0].size() - 1;
        top = 0;
        bottom = matrix.size() - 1;
        x = 0, y = 0;
        

        while(left <= right || top <= bottom){
            // 右 y++
            for(y = left + 1; y <= right; y++){
                pushNum(x, y, matrix);
            }
            y--;
            left++;

            // 下 x++
            for(x = top + 1; x <= bottom; x++){
                pushNum(x, y, matrix);
            }
            x--;
            top++;
            // 左 y--
            for(y = right - 1; y >= left; y--){
                pushNum(x, y, matrix);
            }
            y++;
            right--;
            // 上 x++
            for(x = bottom - 1; x >= top; x--){
                pushNum(x, y, matrix);
            }
            x++;
            bottom--;
        }
        return res;
    }
};

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector(m, 0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> matrix[i][j];
        }
    }
    Solution sol;
    sol.spiralOrder(matrix);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << matrix[i][j] << " " << endl;
        }
    }
}
