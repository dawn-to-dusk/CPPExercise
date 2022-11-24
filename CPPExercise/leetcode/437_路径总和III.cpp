//
//  437_路径总和III.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/8/21.
//

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// dfs
class Solution1 {
public:
    vector<long long> sum;
    long long count;
    long long t;
    Solution1(){
        count = 0;
        t = 0;
    }
    vector<long long> getSum(TreeNode* cur){
        if(cur==nullptr){
            return vector<long long>{};
        }
        vector<long long> sums{cur->val};
        if(cur->val == t){
            count++;
        }
        vector<long long> sumL = getSum(cur->left);
        vector<long long> sumR = getSum(cur->right);
        for(int i = 0; i < sumL.size(); i++){
            if(sumL[i] + cur->val == t){
                count++;
            }
            sums.push_back(sumL[i] + cur->val);
        }
        for(int i = 0; i < sumR.size(); i++){
            if(sumR[i] + cur->val == t){
                count++;
            }
            sums.push_back(sumR[i] + cur->val);
        }
        return sums;
    }
    int pathSum(TreeNode* root, int targetSum) {
        t = targetSum;
        getSum(root);
        return count;
    }
};


// dfs + 前缀和，时间复杂度更低
class Solution {
public:
    unordered_map<long long, int> preSum;
    long long t;
    
    int dfs(TreeNode* node, long long curSum){
        if(node == nullptr){
            return 0;
        }
        
        curSum += node->val;
        int ret = 0;
        if(preSum.find(curSum-t) != preSum.end()){
            ret += preSum[curSum-t];
        }
        preSum[curSum]++;
        ret += dfs(node->left, curSum);
        ret += dfs(node->right, curSum);
        preSum[curSum]--;
        
        return ret;
    }
    int pathSum(TreeNode* root, int targetSum) {
        t = targetSum;
        preSum[0] = 1;
        return dfs(root, 0);
    }
};
