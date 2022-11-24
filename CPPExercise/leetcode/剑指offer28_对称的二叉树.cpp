//
//  剑指offer28_对称的二叉树.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/8/20.
//

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* dfs(TreeNode* root){
        if(root == nullptr){
            return nullptr;
        } else {
            TreeNode* cur = new TreeNode(root->val);
            if(root->left != nullptr){
                cur->right = dfs(root->left);
            }
            if(root->right != nullptr){
                cur->left = dfs(root->right);
            }
            return cur;
        }
    }
    bool cmp(TreeNode* A, TreeNode* B){
        if(A == nullptr || B == nullptr){
            if(A == nullptr && B == nullptr){
                return true;
            } else {
                return false;
            }
        } else {
            if(A->val == B->val){
                return cmp(A->left, B->left) && cmp(A->right, B->right);
            } else {
                return false;
            }
        }
    }
    bool isSymmetric(TreeNode* root) {
        TreeNode* symmetric = dfs(root);
        return cmp(root, symmetric);
    }
};
