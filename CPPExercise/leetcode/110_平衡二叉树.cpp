//
//  110_平衡二叉树.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/8/21.
//

#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int getHight(TreeNode* root){
        if(root == nullptr){
            return 0;
        } else {
            int left = getHight(root->left) + 1;
            int right = getHight(root->right) + 1;
            if(left == 0 || right == 0){
                return -1;
            }
            if(abs(left - right) > 1){
                return -1;
            } else {
                return left > right ? left : right;
            }
        }
    }
    bool isBalanced(TreeNode* root) {
        if(getHight(root) != -1){
            return true;
        } else {
            return false;
        }
    }
};
