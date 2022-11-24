//
//  3.cpp
//  Test
//
//  Created by Baozhu Fang on 2022/9/4.
//

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
 5 6 3
 1 1 2 3 3 4
 2 5 3 4 5 5
 1 3 1 2 1 1
 */

const int MAXN =100000 + 10;
const int MAXM =200000 + 10;
int n, m, k;
int start[MAXM];
int endN[MAXM];
int gas[MAXM];
int G[MAXN][MAXN];
bool flag[MAXN];

int getN(int pos, int cast, int len){
    if(len <= k && pos == n - 1){
        return cast;
    }
    if(flag[pos]){
        return -1;
    }
    if(len > k){
        return -1;
    }
    
    flag[pos] = true;
    int res = 100000;
    for(int i = 1; i < n; i++){
        if(G[pos][i] != -1){
            int tmp = getN(i, cast + G[pos][i], len+1);
            if(tmp == -1){
                continue;
            }
            res = min(tmp, res);
        }
    }
    if(res == 100000){
        flag[pos - 1] = false;
        return -1;
    }
    return res;
}

int main(){
    for(int i = 0; i < n; i++){
        memset(G, -1, sizeof(G[i]));
    }
    memset(flag, false, sizeof(flag));
    
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++){
        cin >> start[i];
    }
    for(int i = 0; i < m; i++){
        cin >> endN[i];
    }
    for(int i = 0; i < m; i++){
        cin >> gas[i];
        G[start[i]][endN[i]] = gas[i];
    }
    cout << getN(0, 0, 0) << endl;
    return 0;
}


