//
//  19_删除链表的倒数第N个节点.cpp
//  Tmp
//
//  Created by Baozhu Fang on 2022/8/12.
//

#include<iostream>
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* pre = new ListNode();
        pre->next = head;
        ListNode* cur = head;
        for(int i = 0; i < n; i++){
            cur = cur->next;
        }

        while(cur != nullptr){
            pre = pre->next;
            cur = cur->next;
        }

        cur = pre->next;
        pre->next = pre->next->next;
        if(cur == head){
            return head->next;
        } else {
            delete cur;
            return head;
        }
    }
};

int main(){
    int n;
    cin >> n;
    ListNode* head = new ListNode();
    ListNode* pre = head;
    for(int i = 0; i < n; i++){
        int val;
        cin >> val;
        ListNode* cur = new ListNode(val);
        pre->next = cur;
        pre = pre->next;
    }
    
    cin >> n;
    Solution sol;
    head = sol.removeNthFromEnd(head->next, n);
    while(head != nullptr){
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}
