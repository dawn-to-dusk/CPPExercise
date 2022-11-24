//
//  3.cpp
//  Test
//
//  Created by Baozhu Fang on 2022/9/13.
//

/*

 小红拿到了一个字符矩阵，矩阵仅由'r、'e'、'd'三种字符组成。她初始站在左上角，每次可以走到一个相邻的字符上(每个字符上、下、左、右最多4个相邻)。但有个限制，小红不能从'r走到d'，从'e'走到r' ,从'd'走到e'，其他情况都能走。
 小红想知道，从左上角走到右下角至少需要多少步?

 输入描述:
 第一行输入两个正整数n和m，代表矩阵的行数和列数。
 接下来的n行，每行输入一个长度为m的字符串，用来表示矩阵。
 1≤n, m ≤500

 输出描述:
 如果小红无法到达右下角，则输出-1。
 否则输出一个整数，代表小红的最少移动步数。
 */


/*
 3 3
 red
 der
 rdr
 
 4
 
 小红可以走r →e →e → d →r，共需要移动4步。
 */

#include <iostream>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 510;
int n, m;
string strs[N];
int matrix[N][N];
int flag[N][N];
int step[4][2] = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1},
};
typedef pair<int,int>PII;

bool check(int x, int y, int xx, int yy)
{
    if(xx < 1 || xx > n || yy < 1 || yy > m){
        return false;
    }
    char u = strs[x][y];
    char v = strs[xx][yy];
    if((u == 'r' && v == 'd') || (u == 'e' && v == 'r') || (u == 'd' && v == 'e')) return false;
    return true;
}

int main(){
    memset(matrix, 0x3f, sizeof (matrix));
    
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        string str;
        cin >> str;
        strs[i] = "0" + str;
    }
    
    queue<PII>q;
    q.push({1, 1});
    matrix[1][1] = 0;
    flag[1][1] = 1;
    while(!q.empty())
    {
        auto[x, y] = q.front();
        q.pop();
        
        flag[x][y] = 0;
        for (int i = 0; i < 4; i ++)
        {
            int xx = x + step[i][0];
            int yy = y + step[i][1];
            if(check(x, y, xx, yy))
            {
                if(matrix[xx][yy] > matrix[x][y] + 1)
                {
                    matrix[xx][yy] = matrix[x][y] + 1;
                    if(!flag[xx][yy])
                    {
                        q.push({xx, yy});
                        flag[xx][yy] = 1;
                    }
                }
            }
        }
    }
    
    if(matrix[n][m] == 0x3f3f3f3f)
        cout << -1 << endl;
    else
        cout << matrix[n][m] << endl;
    
    return 0;
}


