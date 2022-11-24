//
//  剑指offer_32从上到下打印二叉树.cpp
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
    vector<int> res;
    void bfs(TreeNode* root){
        queue<TreeNode*> nodes;
        nodes.push(root);
        while(!nodes.empty()){
            TreeNode* cur = nodes.front();
            nodes.pop();
            res.push_back(cur->val);

            if(cur->left != nullptr){
                nodes.push(cur->left);
            }
            if(cur->right != nullptr){
                nodes.push(cur->right);
            }
        }
    }
    vector<int> levelOrder(TreeNode* root) {
        if(root == nullptr){
            return res;
        }
        bfs(root);
        return res;
    }
};
