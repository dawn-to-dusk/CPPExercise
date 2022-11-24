//
//  剑指offer25_两个链表的第一个公共节点.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/8/21.
//

/**
 两个头节点都走过m+n的长度，一定会在第一个公共节点处相遇
 */

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curA = headA;
        ListNode* curB = headB;
        while(curA != curB){
            if(curA != nullptr){
                curA = curA->next;
            } else {
                curA = headB;
            }
            if(curB != nullptr){
                curB = curB->next;
            } else {
                curB = headA;
            }
        }
        return curA;
    }
};
