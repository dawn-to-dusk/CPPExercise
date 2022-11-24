//
//  剑指offer22_链表中的倒数第k个节点.cpp
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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* first = head;
        ListNode* second = head;
        for(int i = 0; i < k; i++){
            second = second->next;
        }
        while(second != nullptr){
            second = second->next;
            first = first->next;
        }
        return first;
    }
};
