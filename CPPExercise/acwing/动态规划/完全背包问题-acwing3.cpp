//
//  完全背包问题.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/9/12.
//

/*
 任意一个商品可以取无限次
 
 dp[i][j]
 取第i个商品时，可以选择不取、取一次、取两次、取k次
 dp[i][j] = max(
 dp[i-1][j]
 dp[i-1][j-v]+w
 dp[i-1][j-2v]+2w
 ...
 dp[i-1][j-kv]+kw)
 
 同理dp[i][j-v] = max(
 dp[i-1][j-v]
 dp[i-1][j-2v]+w
 dp[i-1][j-3v]+2w
 ...
 dp[i-1][j-kv]+(k-1)w)
 
 故dp[i][j] = max(
 dp[i-1][j]
 dp[i][j-v]+w)
 
 01背包：dp[i][j] = max(dp[i-1][j], dp[i-1][j-v]+w)
 完全背包：dp[i][j] = max(dp[i-1][j], dp[i][j-v]+w)
 差别在于如果取的话，基本当前层的值变化移动，所以优化后的方法不可以方向推，只能正向推
 */

/*
 4 5
 1 2
 2 4
 3 4
 4 5
 
 10
 */

#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1010;
int n, m;
int v[N], w[N];
//int dp[N][N];
//
//int main(){
//    cin >> n >> m;
//    for(int i = 1; i <= n; i++){
//        cin >> v[i]>> w[i];
//    }
//
//    for(int i = 1; i <= n; i++){
//        for(int j = 0; j <= m; j++){
//            dp[i][j] = dp[i-1][j];
//            if(j >= v[i]){
//                dp[i][j] = max(dp[i][j], dp[i][j-v[i]] + w[i]);
//            }
//        }
//    }
//
//    int res = 0;
//    for(int i = 0; i <= m; i++){
//        res = max(res, dp[n][i]);
//    }
//
//    cout << res << endl;
//    return 0;
//}

// 优化
int dp[N];

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> v[i]>> w[i];
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = v[i]; j <= m; j++){
            dp[j] = max(dp[j], dp[j-v[i]] + w[i]);
        }
    }

    cout << dp[m] << endl;
    return 0;
}
