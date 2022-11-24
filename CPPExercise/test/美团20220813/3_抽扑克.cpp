//
//  3_抽扑克.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/8/13.
//
/**
 一堆扑克，每轮依次从顶上抽两张放到牌底，然后再从牌顶抽一张打开，记下扑克号码，
 并从扑克堆中拿出，直至最后一张被打开，根据记下的扑克号码，求出最初扑克堆的顺序
 输入：
 - 第一行 n-扑克张数
 - 第二行 依次记下的扑克号码
 输出：
 最初从顶部到底部的扑克号码
 e.g.
 输入
 4
 1 2 3 4
 输出
 4 2 1 3
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int nums[100000];

int main(){
    cin >> n;

    int ptr = 0;
    for(int i = 0; i < n; i++){
        int val;
        cin >> val;
        for(int j = 0; j < 2; j++){
            while(ptr != -1 && nums[ptr] != 0){
                ptr = (ptr + 1)%n;
            }
            ptr = (ptr + 1)%n;
        }

        while(nums[ptr] != 0){
            ptr = (ptr + 1)%n;
        }
        nums[ptr] = val;
    }

    for(int i = 0; i < n; i++){
        cout << nums[i] << " ";
    }

    return 0;
}

