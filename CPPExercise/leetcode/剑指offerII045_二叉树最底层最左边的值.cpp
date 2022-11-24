//
//  剑指offerII045_二叉树最底层最左边的值.cpp
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
    int l;
    int num;

    void setNum(TreeNode* root, int len){
        if(len > l){
            l = len;
            num = root->val;
        }
        if(root->left != nullptr){
            setNum(root->left, len+1);
        }
        if(root->right != nullptr){
            setNum(root->right, len+1);
        }
    }
    int findBottomLeftValue(TreeNode* root) {
        setNum(root, 1);
        return num;
    }
};
