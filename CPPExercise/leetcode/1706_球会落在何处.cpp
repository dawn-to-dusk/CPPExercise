//
//  1706_球会落在何处.cpp
//  Tmp
//
//  Created by Baozhu Fang on 2022/8/12.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> flag;
    int n, m;
    int dfs(vector<vector<int>>& grid, int x, int y){
        if(flag[x][y] != 0){
            return flag[x][y];
        }
        
        if(grid[x][y] == 1){
            //'\'
            if(x == n-1 || y == m-1){
                // 边界点
                
                if(x == n-1 && y == m-1){
                    // "\|" 右下角
                    flag[x][y] = -1;
                } else if(x == n-1){
                    // 最底层
                    if(grid[x][y+1] == 1){
                        // "\\"
                        flag[x][y] = y+1;
                    } else {
                        // "\/"
                        flag[x][y] = -1;
                    }
                } else if(y == m-1){
                    // 最右边 "\|"
                    flag[x][y] = -1;
                }
            } else {
                // 非边界点
                if(grid[x][y+1] == 1){
                    // "\\"
                    flag[x][y] = dfs(grid, x+1, y+1);
                } else {
                    // "\/"
                    flag[x][y] = -1;
                }
            }
        } else {
            // '/'
            if(x == n-1 || y == 0){
                // 边界点
                
                if(x == n-1 && y == 0){
                    // "|/" 左下角
                    flag[x][y] = -1;
                } else if(x == n-1){
                    // 最底层
                    if(grid[x][y-1] == 1){
                        // "\/"
                        flag[x][y] = -1;
                    } else {
                        // "//"
                        flag[x][y] = y-1;
                    }
                } else if(y == 0){
                    // 最左边 "|/"
                    flag[x][y] = -1;
                }
            } else {
                // 非边界点
                if(grid[x][y-1] == 1){
                    // "\/"
                    flag[x][y] = -1;
                } else {
                    // "//"
                    flag[x][y] = dfs(grid, x+1, y-1);
                }
            }
        }
        
        return flag[x][y];
    }
    
    vector<int> findBall(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        flag.resize(n);
        for(int i = 0; i < n; i++){
            flag[i].resize(m);
        }
        
        
        vector<int> res;
        for(int i = 0; i < m; i++){
            res.push_back(dfs(grid, 0, i));
        }
        return res;
    }
};


int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector(m, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }
    
    Solution sol;
    vector<int> res = sol.findBall(grid);
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << endl;
    }
}
