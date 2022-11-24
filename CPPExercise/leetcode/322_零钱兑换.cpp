//
//  322_零钱兑换.cpp
//  Tmp
//  F(s) = F(s - c) + 1
//
//  Created by Baozhu Fang on 2022/8/13.
//

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int amount;
    vector<int> count;
    int getCoin(vector<int>& coins, int remain){
        if(remain == 0){
            return 0;
        }
        if(remain < 0){
            return amount + 1;
        }
        // 用一个vector记录值避免重复计算
        if(count[remain] != 0) {
            return count[remain];
        }
        
        int minCount = amount + 1;
        for(int i = 0; i < coins.size(); i++){
            minCount = min(getCoin(coins, remain - coins[i]) + 1, minCount);
        }
        count[remain] = minCount;
        return count[remain];
    }

    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0){
            return 0;
        }
        this->amount = amount;
        count.resize(amount);
        int res = getCoin(coins, amount);
        return res > amount ? -1 : res;
    }
};

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> coins(n);
    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }
    Solution sol;
    cout << sol.coinChange(coins, m) << endl;
}
