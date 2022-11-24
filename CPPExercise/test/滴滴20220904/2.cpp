//
//  1.cpp
//  Test
//
//  Created by Baozhu Fang on 2022/9/4.
//
/*
 2
 0 1
 0 10
 0 1
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int MAXN = 70010;
int n;
int L[MAXN];
int R[MAXN];
int T[MAXN];

int nums[MAXN];

int getBeaty(int t){
    int res = t % 10;
    t = t / 10;
    while(t != 0){
        res = res ^ (t % 10);
        t = t / 10;
    }
    return res;
}

int main(){
    cin >> n;
    for(int i = 0;i < n; i++){
        cin >> L[i];
    }
    for(int i = 0;i < n; i++){
        cin >> R[i];
    }
    for(int i = 0;i < n; i++){
        cin >> T[i];
    }
    
    for(int i = 0; i < n; i++){
        int cnt = 0;
        for(int j = L[i]; j <= min(R[i], T[i]); j++){
            if(getBeaty(j) == T[i]){
                cnt++;
            }
        }
        cout << cnt << " ";
    }
    cout << endl;
    return 0;
}
