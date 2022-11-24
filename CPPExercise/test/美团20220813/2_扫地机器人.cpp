//
//  2_扫地机器人.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/8/13.
//
/*
 房间为n*m的方格，扫干净为每个格子都扫一遍
 可以给机器人下达上下左右的指令
 机器人初始在（0，0）位置，认为该位置已经扫干净
 输入：给出一系列指令 W-上 S-下 A-左 D-右
 输出：判断机器人能够扫干净
 - 能，输出Yes，以及用了几条指令后扫干净
 - 不能，输出No，以及还有多个格子没扫
 保证机器人不会超出房间范围
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m, k;
vector<vector<int>> grid;

int check(){
    int count = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 0){
                count++;
            }
        }
    }
    return count;
}

int main(){
    cin >> n >> m >> k;
    grid.resize(n);
    for(int i = 0; i < n; i++){
        grid[i].resize(m);
    }
    grid[0][0] = 1;

    string str;
    cin >> str;
    int x = 0, y = 0;
    int resOk = 0;
    for(int i = 0; i < k; i++){
        switch (str[i]) {
            case 'W':
                grid[--x][y] = 1;
                break;
            case 'A':
                grid[x][--y] = 1;
                break;
            case 'S':
                grid[++x][y] = 1;
                break;
            case 'D':
                grid[x][++y] = 1;
                break;
            default:
                break;
        }
        resOk++;
        if(check() == 0){
            cout << "Yes\n" << resOk << endl;
            return 0;
        }
    }

    cout << "No\n" << check() << endl;
    return 0;

}


