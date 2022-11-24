//
//  2.cpp
//  Test
//
//  Created by Baozhu Fang on 2022/9/8.
//

#include<iostream>
using namespace std;

struct TreeNode {
   int val;
   struct TreeNode *left;
   struct TreeNode *right;
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };
 
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param tree TreeNode类
     * @return int整型
     */
//    long long res;
//    Solution(){
//        //res = 0;
//    }
    long long setNum(TreeNode* tree){
        if(tree->left == nullptr && tree->right == nullptr){
            tree->val = 1;
            //res += 1;
            return 1;
        }
        
        long long left = setNum(tree->left) % 1000000007;
        long long right = setNum(tree->right) % 1000000007;
        if(left == right){
        } else if(left < right){
            tree->left->val = (tree->left->val + (right - left)) % 1000000007;
            //res = (res + (right - left)) % 1000000007;
        } else {
            tree->right->val = (tree->right->val + (left - right)) % 1000000007;
            //res = (res + (left - right)) % 1000000007;
        }
        
        tree->val = 1;
        //res = (res + 1) % 1000000007
        return (left + right + tree->val) % 1000000007;
    }
    
//    long long getSum(TreeNode* tree){
//        if(tree->left == nullptr && tree->right == nullptr){
//            return tree->val % (1000000007);
//        }
//        return (tree->val % (1000000007) + getSum(tree->left) % (1000000007) + getSum(tree->right) % (1000000007))% (1000000007);
//    }
    
    int getTreeSum(TreeNode* tree) {
        // write code here
        long long left = setNum(tree->left) % 1000000007;
        long long right = setNum(tree->right) % 1000000007;
        long long res = (left + right + 1) % 1000000007;
        
        if(left == right){
        } else if(left < right){
            tree->left->val = (tree->left->val + (right - left)) % 1000000007;
            res = (res + (right - left)) % 1000000007;
        } else {
            tree->right->val = (tree->right->val + (left - right)) % 1000000007;
            res = (res + (left - right)) % 1000000007;
        }
        //tree->val = 1;
        
        
        return res;
    }
};

