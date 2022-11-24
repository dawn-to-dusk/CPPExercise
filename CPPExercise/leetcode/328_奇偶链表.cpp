//
//  328_奇偶链表.cpp
//  Tmp
//
//  Created by Baozhu Fang on 2022/8/13.
//

#include<iostream>
#include<vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode* aCur = head;
        ListNode* bHead = head->next;
        ListNode* bCur = bHead;
        ListNode* cur = bCur->next;
        while(cur != nullptr){
            aCur->next = cur;
            aCur = aCur->next;
            cur = cur->next;

            if(cur != nullptr){
                bCur->next = cur;
                bCur = bCur->next;
                cur = cur->next;
            }
        }
        bCur->next = nullptr;
        aCur->next = bHead;
        return head;
    }
};
