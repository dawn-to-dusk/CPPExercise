//
//  222_完全二叉树的节点个数.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/9/22.
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
    int countNodes(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        int left = countNodes(root->left);
        int right = countNodes(root->right);
        return left + right + 1;
    }
};
