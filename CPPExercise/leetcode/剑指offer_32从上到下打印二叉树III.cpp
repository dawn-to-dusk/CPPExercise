//
//  剑指offer_32从上到下打印二叉树III.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/8/19.
//

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    vector<vector<int>> res;
    void reverse(vector<int> &nums){
        stack<int> stk;
        for(int i = 0; i < nums.size(); i++){
            stk.push(nums[i]);
        }
        for(int i = 0; i < nums.size(); i++){
            nums[i] = stk.top();
            stk.pop();
        }
    }
    void bfs(TreeNode* root){
        if(root == nullptr){
            return;
        }
        queue<TreeNode*> nodes;
        nodes.push(root);
        queue<bool> flags;
        flags.push(true);
        vector<int> tmp;
        bool forward = true;
        while(!nodes.empty()){
            TreeNode* cur = nodes.front();
            nodes.pop();
            tmp.push_back(cur->val);

            bool f = flags.front();
            flags.pop();
            if(cur->left != nullptr){
                nodes.push(cur->left);
                flags.push(false);
            }
            if(cur->right != nullptr){
                nodes.push(cur->right);
                flags.push(false);
            }
            
            if(f){
                flags.pop();
                flags.push(true);
                if(forward){
                    forward = false;
                } else {
                    reverse(tmp);
                    forward = true;
                }
                res.push_back(tmp);
                tmp.clear();
            }
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        bfs(root);
        return res;
    }
};
