//
//  多重背包问题_二进制优化-acwing5.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/9/12.
//

/*
 三层循环的多重背包，只能用于n<=100
 但可以通过二进制优化简化为01背包问题
 
 简单来说，第i个物品有s个，可以拆分为s个i物品
 如果直接拆分，一个商品拆为n个，时间复杂度将为m*n*s，如果是1000-2000级别的数据，可能会过大
 如果采用二进制优化拆分，一个商品拆为logn个，可以降低复杂度
 
 二进制拆分：拆为logn向上取整
 7=>1 2 4
 0: 00 0
 1: 01 1
 2: 10 2
 3: 11 1+2
 4: 100 4
 5: 101 1+4
 6: 110 2+4
 7: 111 1+2+4
 
 10=>1 2 4 3
 7: 1 + 2 + 4
 8: 1 + 4 + 3
 9: 2 + 4 + 3
 10: 1 + 2 + 4 + 3
 */

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

/*
 0<N≤1000
 0<V≤2000
 0<vi,wi,si≤2000
 
 4 5
 1 2 3
 2 4 1
 3 4 3
 4 5 2
 
 10
 */

const int N = 2010;
int dp[N];

struct Good{
    int v;
    int w;
};

int n, m;

int main(){
    cin >> n >> m;
    vector<Good> goods;
    for(int i = 0 ; i< n; i++){
        int v, w, s;
        cin >> v >> w >> s;
        
        for(int k = 1; k <= s; k = k * 2){
            s -= k;
            goods.emplace_back(Good{v * k, w * k});
        }
        if(s > 0){
            goods.emplace_back(Good{v * s, w * s});
        }
    }
    
    for(auto g : goods){
        for(int j = m; j >= g.v; j--){
            dp[j] = max(dp[j], dp[j-g.v] + g.w);
        }
    }
    
    cout << dp[m] << endl;
    return 0;
}
