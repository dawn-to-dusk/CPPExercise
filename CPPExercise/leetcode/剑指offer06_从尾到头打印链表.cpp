//
//  剑指offer06_从尾到头打印链表.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/8/11.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while(cur != nullptr){
            ListNode* nextN = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nextN;
        }

        vector<int> res;
        while(pre != nullptr){
            res.push_back(pre->val);
            pre = pre->next;
        }

        return res;
    }
    vector<int> reversePrint1(ListNode* head) {
        stack<int> stk;
        while(head != nullptr){
            stk.push(head->val);
            head = head->next;
        }
        
        vector<int> res;
        while(!stk.empty()){
            res.push_back(stk.top());
            stk.pop();
        }

        return res;
    }
};

int main(){
    Solution sol;
    int n;
    cin >> n;
    ListNode* head= new ListNode(-1);
    ListNode* pre = head;
    for(int i = 0; i < n; i++){
        ListNode* cur = new ListNode(i);
        pre->next = cur;
        pre = pre->next;
        
    }
    
//    vector<int> res = sol.reversePrint(head);
//    for(int i = 0; i < res.size(); i++){
//        cout << res[i] << endl;
//    }

    vector<int> res = sol.reversePrint1(head);
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << endl;
    }
}
