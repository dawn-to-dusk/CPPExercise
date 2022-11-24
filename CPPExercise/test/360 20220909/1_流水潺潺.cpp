//
//  1_流水潺潺.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/9/10.
//

/*
 最近，小七发现了一处干涸的河道。
 河道不同的位置高度也不相同，从河道起点到终点有n个位置，位置i的高度可以表示为hi(1、n是河道的两端)，两端高度无穷大。
 本着环保的精神，小七希望在恰好一个位置注入水,水会从高处向低处流动，但原来的位置仍然有水。
 具体来说就是，如果在i处注入水，如果有某一个相邻的格子j高度严格小于i hj<hl的，j处也会有水。对于j相邻的格子也是如此。
 现在小七想知道，通过一次注入水源最多可以使多少河道有水。
 输入描述
 第一行一个正整数n(1<=n=5000）第二行n个正整数，第i个表示位置i处河道的高度hi（0<hi<1000000000）
 输出描述
 输出仅一行，即答案
 
 input
 5
 5 1 2 1 5
 output
 3
 */

// ak

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 5000
//1000000000

int n;
vector<int>nums;
vector<int>sum;

int getSum(int pos){
    if(sum[pos] != 0){
        return sum[pos];
    }
    
//    if(pos == 0 || pos == n - 1){
//        return 1;
//    }
    int left = 0;
    int right = 0;
    if(pos + 1 < n && nums[pos] > nums[pos+1]){
        left = getSum(pos+1);
    }
    if(pos - 1 >= 0 && nums[pos] > nums[pos-1]){
        right = getSum(pos-1);
    }
    
    sum[pos] = left + right + 1;
    return sum[pos];
}

int main(){
    cin >> n;
    nums.resize(n);
    sum.resize(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    
    if(n == 1){
        cout << 1 << endl;
        return 0;
    } else if(n == 2){
        if(nums[0] == nums[1]){
            cout << 1 << endl;
        } else {
            cout << 2 << endl;
        }
        return 0;
    }
    
    
    int res = 0;
    for(int i = 0; i < n; i++){
        res = max(res, getSum(i));
    }
    
    cout << res << endl;
    return 0;
}

