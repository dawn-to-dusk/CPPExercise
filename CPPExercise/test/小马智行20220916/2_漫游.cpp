//
//  z2.cpp
//  Test
//
//  Created by Baozhu Fang on 2022/9/16.
//

/*
 给定一个N*M的网格，每个格子上写着^v<，>四种字符之一，分别表示上下左右四个方向。你可以任意选择一个格子为起点出发，每一步必须朝着当前格子上写的方向移动到相邻的一个格子，如果走出网格边界则游戏立刻结束。问最多可以经过多少个不同的格子?
 输入描述:
 第一行两个正整数N，M;
 之后N行，每行M个字符，表示每个格子对应的方向。
 输出描述:
 输出一个整数，表示可能经过的不同格子的数量。
 
 2 3
 ^v<
 >>^
 5
 
 
 2 3
 vvv
 <<<
 4
 
 对于前20%的数据，N，M<=10;
 对于前40%的数据，N，M <=50;
 对于前80%的数据，N，M <=500;
 对于100%的数据，N，M <= 2000。
 */

// 10%

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<string.h>
using namespace std;

const int N = 500;
char matrix[N][N];
int dp[N][N];
int  flag[N][N];


struct PI{
    int x;
    int y;
};

int n, m;
unordered_map<char, PI> um;

bool check(int xx, int yy){
    if(xx < 0 || xx >= n || yy < 0 || yy >= m){
        return false;
    }
    
    return true;
}


int getNum(int x, int y, int steps, vector<PI> &nums){
    if(flag[x][y] != 0){
        for(int i = flag[x][y] - 1; i < steps; i++){
            dp[nums[i].x][nums[i].y] = steps -1;
        }
        return steps - 1;
    }
    flag[x][y] = steps;
    nums.emplace_back(PI{x, y});

    int xx = x + um[matrix[x][y]].x;
    int yy = y + um[matrix[x][y]].y;

    if(check(xx, yy)){
        return getNum(xx, yy, steps+1, nums);
    } else {
        return steps;
    }
}

int main(){
    um['^'] = {-1, 0};
    um['v'] = {1, 0};
    um['<'] = {0, -1};
    um['>'] = {0, 1};

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        for(int j = 0; j < m; j++){
            matrix[i][j] = str[j];
        }
    }

    int res = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            memset(flag, false, sizeof(flag));
            if(dp[i][j] == 0){
                vector<PI> nums;
                dp[i][j] = getNum(i, j, 1, nums);
            }
            
            res = max(res, dp[i][j]);
        }
    }
    
    cout << res << endl;
    return 0;
    
}

