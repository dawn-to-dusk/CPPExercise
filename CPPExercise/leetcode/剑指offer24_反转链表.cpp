//
//  剑指offer24_反转链表.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/8/11.
//

#include <stdio.h>
#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while(cur != nullptr){
            ListNode* nextN = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nextN;
        }

        return pre;
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
    head = sol.reverseList(head);
    return 0;
}

