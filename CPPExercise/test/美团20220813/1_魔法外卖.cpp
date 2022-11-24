//
//  1_魔法送外卖.cpp
//  CPPExercise
//
//  一次送一个单子，可以选择消耗时间t送，也可以选择用魔法不消耗时间送
//  每个外卖订单有截止时间，从0时刻开始收到订单，要保证截止时间之前送到
//  输入：
//  - 第一行 n-订单数 t-一次外卖消耗时间  1<=n<=1e5 1<=t<=100
//  - 第二行 n个订单的截止时间 送达时间在[1,1e]之间
//  输出：
//  最少用魔法的次数
//
//  Created by Baozhu Fang on 2022/8/13.
//

#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, t;
    cin >> n >> t;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());

    int count = 0;
    int cur = 0;
    for(int i = 0; i < n; i++){
        if(cur + t <= nums[i]){
            cur += t;
        } else {
            count++;
        }
    }
    cout << count << endl;
}
