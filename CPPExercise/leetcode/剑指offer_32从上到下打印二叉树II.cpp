//
//  剑指offer_32从上到下打印二叉树II.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/8/19.
//

#include <iostream>
#include <vector>
#include <queue>
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
    void bfs(TreeNode* root){
        if(root == nullptr){
            return;
        }
        queue<TreeNode*> nodes;
        nodes.push(root);
        queue<bool> flags;
        flags.push(true);
        vector<int> tmp;
        while(!nodes.empty()){
            TreeNode* cur = nodes.front();
            nodes.pop();
            tmp.push_back(cur->val);
            if(cur->left != nullptr){
                nodes.push(cur->left);
                flags.push(false);
            }
            if(cur->right != nullptr){
                nodes.push(cur->right);
                flags.push(false);
            }
            bool flag = flags.front();
            flags.pop();
            if(flag){
                flags.pop();
                flags.push(true);
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
