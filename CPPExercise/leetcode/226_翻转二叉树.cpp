//
//  226_翻转二叉树.cpp
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
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> nodes;
        nodes.push(root);
        while(!nodes.empty()){
            TreeNode* cur = nodes.front();
            nodes.pop();
            if(cur != nullptr){
                TreeNode* tmp = cur->left;
                cur->left = cur->right;
                cur->right = tmp;

                nodes.push(cur->left);
                nodes.push(cur->right);
            }
        }
        return root;
    }
};
