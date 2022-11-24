//
//  1_勇往直前.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/9/5.
//

/*
 某公司开发了一款“勇往直静”的游戏，游戏中，玩家需要控制角色路向前跑，一边躲开障碍物一边捡拾路边随机出现的金币，金市的价值不等，并且其价值会显示在金币上方。为了增加游戏的难度，现在游戏中规定，玩家每次捡拾某金币后，不能马上捡拾此金币相邻的金币(即捡起一个金币后，相邻的下一个金币不允许捡起)，否则游戏失败。现在要求你为此设计一个算法，计算出指定金币数能捡拾的最大值。
 
 输入描述:
 输入n个金币价值，用整数表示，数字之间用空格隔开
 输出描述:
 输出上面n个金币在规则内捡拾到的金币的最大值。
 
 e.g.
 input:
 1 2 3 1
 output:
 4
 
 input:
 2 7 9 3 1
 output:
 12
 
 ak
 */


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 样例

vector<int> sum;
vector<int> nums;

int getSum(int i){
    if(sum[i] != 0){
        return sum[i];
    }

    if(i == 0){
        sum[0] = nums[0];
    } else if(i == 1){
        sum[1] = nums[1];
    } else if(i == 2){
        sum[2] = nums[0] + nums[2];
    } else{
        sum[i] = max(nums[i] + getSum(i-3), nums[i] + getSum(i-2));
    }

    return sum[i];
}

int main() {
    // 根据输入描述获取入参

    int t;
    while (cin >> t) {
        nums.push_back(t);
    }
    int n = nums.size();

    sum.resize(n);
    cout << max(getSum(n-1), getSum(n-2)) << endl;
    return 0;
}

