//
//  面试题02_05_链表求和.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/9/1.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int extra = 0;
        ListNode* head = l1;
        ListNode* p1 = new ListNode();
        ListNode* p2 = new ListNode();
        p1->next = l1;
        p2->next = l2;
        while(p1->next != nullptr && p2->next != nullptr){
            int tmp = p1->next->val + p2->next->val + extra;
            p1->next->val = tmp % 10;
            extra = tmp / 10;
            p1 = p1->next;
            p2 = p2->next;
        }
        while(p1->next != nullptr && extra != 0){
            int tmp = p1->next->val + extra;
            p1->next->val =tmp % 10;
            extra = tmp / 10;
            p1 = p1->next;
        }
        while(p2->next != nullptr) {
            int tmp = p2->next->val + extra;
            p1->next = new ListNode(tmp % 10);
            extra = tmp / 10;
            p1 = p1->next;
            p2 = p2->next;
        }
        while(extra != 0){
            p1->next = new ListNode(extra % 10);
            extra = extra / 10;
            p1 = p1->next;
        }
        return head;

    }
};
