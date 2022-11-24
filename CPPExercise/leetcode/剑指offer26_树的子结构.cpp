//
//  剑指offer26_树的子结构.cpp
//  CPPExercise
//  动态规划
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
    bool cmp(TreeNode* A, TreeNode* B){
        if(B == nullptr){
            return true;
        }
        if(A == nullptr) {
            return false;
        }

        if(A->val != B->val){
            return false;
        }
        return cmp(A->left, B->left) && cmp(A->right, B->right);
    }
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(A == nullptr || B == nullptr){
            return false;
        }
        if(cmp(A, B)){
            return true;
        }
        if(isSubStructure(A->left, B)){
            return true;
        }
        if(isSubStructure(A->right, B)){
            return true;
        }
        return false;
    }
};
