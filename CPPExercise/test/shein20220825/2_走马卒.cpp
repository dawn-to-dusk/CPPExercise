/**
 棋盘上A点有一个过河卒，需要走到目标B点。卒行走的规则：可以向下、或者向右。同时在棋盘上C点有一个对方的马，该马所在的点和所有跳跃一步可达的点称为对方马的控制点。因此称之为“马拦过河卒”。

 棋盘用坐标表示，A点(0, 0)、B点(n, m)(n, m为不超过20的整数)，同样马的位置坐标是需要给出的。

 现在要求你计算出卒从A点能够到达B点的路径的条数，假设马的位置是固定不动的，并不是卒走一步马走一步
 */


#include<iostream>
#include<vector>
using namespace std;

long long A[30][30];
long long B[30][30];

int steps[9][2] = {
    {0, 0},
    {-2, -1},
    {-2, 1},
    {-1, -2},
    {-1, 2},
    {1, -2},
    {1, 2},
    {2, -1},
    {2, 1},
};

int main(){
    int bx, by, x, y;
    cin >> bx >> by >> x >> y;
    
    for(int i = 0; i < 9; i++){
        A[x + steps[i][0]][y + steps[i][1]] = 1;
    }
    
    B[0][0] = 1;
    for(int i = 0; i <= bx ; i++){
        for(int j = 0; j <= by ; j++){
            if(A[i][j] != 1 && B[i][j] == 0){
                B[i][j] = B[i - 1][j] + B[i][j - 1];
            }
        }
    }
    
    cout << B[bx][by] << endl;
    return 0;
}

