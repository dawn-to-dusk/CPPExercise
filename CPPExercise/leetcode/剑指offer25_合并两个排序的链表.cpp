//
//  剑指offer25_合并两个排序的链表.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/8/21.
//

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* cur = head;
        while(l1 != nullptr && l2 != nullptr){
            if(l1->val <= l2->val){
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if(l1 != nullptr){
            cur->next = l1;
        } else {
            cur->next = l2;
        }
        return head->next;
    }
};
