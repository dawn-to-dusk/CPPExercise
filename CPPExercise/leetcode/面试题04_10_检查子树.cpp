//
//  面试题04_10_检查子树.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/9/1.
//

#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    bool isEqualTree(TreeNode* t1, TreeNode* t2){
        if(t1 == t2){
            return true;
        } else if(t1 == nullptr || t2 == nullptr){
            return false;
        } else {
            return (t1->val == t2->val) && isEqualTree(t1->right, t2->right) && isEqualTree(t1->left, t2->left);
        }
    }
    bool checkSubTree(TreeNode* t1, TreeNode* t2) {
        if(t2 == nullptr){
            return true;
        } else if(t1 == nullptr){
            return false;
        }

        return isEqualTree(t1, t2)|| checkSubTree(t1->right, t2) || checkSubTree(t1->left, t2);
    }
};
