//
//  1.cpp
//  Test
//
//  Created by Baozhu Fang on 2022/9/8.
//

#include<iostream>
#include<vector>
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
     * @param preOrder int整型vector
     * @param inOrder int整型vector
     * @return TreeNode类vector
     */
    vector<TreeNode*> res;
    
    
    vector<TreeNode*> buildTree(vector<int>& preOrder, vector<int>& inOrder){
        if(preOrder.size() == 0 || inOrder.size() == 0){
            return vector<TreeNode*> {};
        }
        //TreeNode root = TreeNode(preOrder[0]);
        vector<TreeNode*> roots;
        
        
        
        for(int i = 0;i < preOrder.size(); i++){
            if(preOrder[0] == inOrder[i]){
                vector<int> preLeft;
                preLeft.assign(preOrder.begin() + 1, preOrder.begin() + i + 1);
                vector<int> preRight;
                preRight.assign(preOrder.begin()+ i + 1, preOrder.end());
                vector<int> inLeft;
                vector<int> inRight;
                inLeft.assign(inOrder.begin(), inOrder.begin() + i);
                inRight.assign(inOrder.begin() + i + 1, inOrder.end());
                vector<TreeNode*> leftTmp = buildTree(preLeft, inLeft);
                vector<TreeNode*> rightTmp = buildTree(preRight, inRight);
                for(int j = 0; j < leftTmp.size(); j++){
                    for(int k = 0; k < rightTmp.size(); k++){
                        TreeNode root = TreeNode(preOrder[0]);
                        root.left = leftTmp[j];
                        root.right = rightTmp[k];
                        roots.push_back(&root);
                    }
                }
                
            }
        }
        
        return roots;
    }
    vector<TreeNode*> getBinaryTrees(vector<int>& preOrder, vector<int>& inOrder) {
        // write code here
        
        return buildTree(preOrder, inOrder);
    }
};

