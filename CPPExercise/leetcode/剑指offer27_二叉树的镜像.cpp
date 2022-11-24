//
//  剑指offer27_二叉树的镜像.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/8/20.
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
    void dfs(TreeNode* root){
        if(root == nullptr){
            return;
        } else {
            TreeNode* left = root->left;
            root->left = root->right;
            root->right = left;
        }
        dfs(root->left);
        dfs(root->right);
    }
    TreeNode* mirrorTree(TreeNode* root) {
        dfs(root);
        return root;
    }
};
