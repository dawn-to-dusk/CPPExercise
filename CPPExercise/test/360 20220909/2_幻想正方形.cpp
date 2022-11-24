//
//  2_幻想正方形.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/9/9.
//

/*
 一日，小 A 走在路上时看到路边摆着一面大镜子，他对着镜子注视了起来，他发现自己穿越到了另一个世界！
 这个世界很奇怪：他所在的地方可视为一个n行m列的矩阵，每一个位置上都有一个不小于0的整数或者﹣1。
 这时，他的耳边响起了一个很空灵的声音，如果你想要回到原来的世界，你就需要解决下面的问题：
 你需要在整个矩阵上选择一个正方形区域，使得区域内不存在负数，并且该区域内的数字之和最大。”
 然而这个问题对于小 A 来说还是太难了，所以他请了你来帮忙解决这个问题
 
 输入描述
 第一行一个正整数 T ，表示一共有T组数据，对于每组数据，第一行两个正整n、m，含义见题面
 接下来一个n行m列的整数矩阵aij
 1 ≤ n ,m ≤ 500, 1≤ T ≤ 5, aij € {-1,[0,100]}
 
 输出描述
 对于每组数据，输出一行一个正整数，表示满足条件的最大值，如果不存在则输出0
 
 input
 1
 4 4
 3 0 5 6
 0 9 -1 4
 -1 8 1 1
 4 -1 5 -1
 output
 12
 提示
 选择左上角的2*2正方形，和为3+0+0+9=12
 */


// 考后复盘
#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;

/*
 2
 4 4
 3 0 5 6
 0 9 -1 4
 -1 8 1 1
 4 -1 5 -1
 4 4
 3 0 5 6
 0 9 9 9
 -1 8 1 1
 4 -1 5 -1
 */

int n, m;
int nums[510][510];


int getSum(int x, int y, int t){
    if(x+t >= n || y + t >= m){
        return 0;
    }
    
    int cur = 0;
    if(nums[x+t][y+t] >= 0){
        cur += nums[x+t][y+t];
        for(int i = 0; i < t; i++){
            if(nums[x+i][y+t] >= 0 && nums[x+t][y+i] >= 0){
                cur += nums[x+i][y+t] + nums[x+t][y+i];
            } else {
                return 0;
            }
        }
    } else {
        return 0;
    }
    
    return cur + getSum(x, y, t+1);
}



int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n >> m;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> nums[i][j];
            }
        }
        
        
        int res = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int cur = getSum(i, j, 0);
                res = max(cur, res);
            }
        }
        
        cout << res << endl;
    }
    return 0;
}
