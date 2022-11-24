//
//  2.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/9/12.
//

/*
 4 5
 1 2
 2 4
 3 4
 4 5
 
 8
 */

/*
 dp[i][j] 表示前i个物品体积为j时的最大价值
 - 不取第i个物品 dp[i-1][j]
 - 取第i个午评 dp[i][j-v[i]] + w[i]
 */

#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1010;
int n, m;
int v[N], w[N];


//int dp[N][N];
//// 堆变量默认初始化为0
//
//int main(){
//    cin >> n >> m;
//    for(int i = 1; i <= n; i++){ // 把0列空出来，因为变量转移时需要初始值
//        cin >> v[i] >> w[i];
//    }
//
//    for(int i = 1; i <= n; i++){
//        for(int j = 0; j <= m; j++){
//            dp[i][j] = dp[i-1][j];
//            if(j >= v[i]){ // j >= v[i] 才有可能取i
//                dp[i][j] = max(dp[i][j], dp[i-1][j-v[i]] +w[i]);
//            }
//        }
//    }
//
//    int res = 0;
//    for(int i = 0; i <= m; i++){
//        res = max(res, dp[n][i]);
//    }
//    cout << res << endl;
//    return 0;
//}


// 优化
/*
 1. 二维数组 -> 一维数组
 二维数组中，实际上每次循环我们只用到了上一层数组，并不需要用上一层数组（最后取值时用到的也是最后一层的最大值）
 故可以考虑用一维数组
 
 2. 重量正序取 -> 重量逆序取
 如果使用一维数组，
 即 dp[i][j] = max(dp[i][j], dp[i-1][j-v[i]] +w[i]); 变为 dp[j] = max(dp[j], dp[j-v[i]] +w[i]);
 需要保证max中的第二位实际指代上一层数据
 如果使用逆序取重量，dp[j]即表示当前这么多商品重量不超过j的最大值（仍然使用二维循环对dp赋值）
 因为wi > 0，dp[j-v[i]]一定与dp[j]是不同的
 
 3. 结果直接取dp[m]
 dp[j]初始都是0，均从0转移过来
 dp[j]即表示当前这么多商品重量不超过j的最大值
 */


int dp[N];
// 堆变量默认初始化为0

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){ // 把0列空出来，因为变量转移时需要初始值
        cin >> v[i] >> w[i];
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = m; j >= v[i]; j--){
            dp[j] = max(dp[j], dp[j-v[i]] +w[i]);
        }
    }
    
    cout << dp[m] << endl;
    return 0;
}


// 如果是求体积为m时的最大值
// 可以讲dp初始值赋值为-INF，再取dp[m]
