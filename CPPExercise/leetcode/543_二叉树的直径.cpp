//
//  543_二叉树的直径.cpp
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
    int maxN;
    Solution(){
        maxN = 0;
    }
    int getCurMax(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int left = getCurMax(root->left);
        int right = getCurMax(root->right);
        maxN = max(maxN, left + right);
        return (left > right ? left : right) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        getCurMax(root);
        return maxN;
    }
};
