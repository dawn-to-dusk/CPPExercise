//
//  剑指offer18_删除链表中的节点.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/8/21.
//
#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if(head->val == val){
            return head->next;
        }
        ListNode* pre = new ListNode(0);
        pre->next = head;
        ListNode* cur = head;
        while(cur != nullptr){
            if(cur->val == val){
                pre->next = cur->next;
                delete cur;
                return head;
            }
            pre = pre->next;
            cur = cur->next;
        }
        return head;
    }
};
