//
//  5_二叉树找金钱.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/8/13.
//

/**
 一颗二叉树，根节点为1，节点k的左孩子为2*k，右孩子为2*k+1
 每个节点有一定的钱数，从根节点走到叶子节点，最多能拿到多少钱？
 e.g.
 输入：
 3
 5 7 8
 输出：
 13
 */

#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int cur = 0;
int n;
vector<int> nums;

int dfs(int pos){
    if(pos > n){
        return 0;
    }
    return max(nums[pos] + dfs(pos * 2), nums[pos] + dfs(pos * 2 + 1));
}

int main(){
    cin >> n;
    nums.push_back(-1);
    for(int i = 0; i < n; i++){
        int val;
        cin >> val;
        nums.push_back(val);
    }

    cout << dfs(1) << endl;
    return 0;
}
