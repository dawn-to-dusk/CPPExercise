//
//  148_排序链表.cpp
//  Tmp
//
//  Created by Baozhu Fang on 2022/8/13.
//

/**
 注意每次归并返回需要将最后一位置为空，不然可能会出现环状链表
 */

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
    // 冒泡排序，时间复杂度过高
//    ListNode* bubleSortList(ListNode* head) {
//        ListNode* newHead = new ListNode;
//        newHead->next = head;
//
//        ListNode* ok = nullptr;
//        while(newHead->next != ok){
//            ListNode* pre = newHead;
//            ListNode* cur = newHead->next;
//            bool flag = true;
//            while(cur->next != ok){
//                if(cur->val > cur->next->val){
//                    pre->next = cur->next;
//                    cur->next = cur->next->next;
//                    pre = pre->next;
//                    pre->next = cur;
//                    flag = false;
//                } else {
//                    pre = pre->next;
//                    cur = cur->next;
//                }
//            }
//            ok = cur;
//            if(flag){
//                break;
//            }
//        }
//        return newHead->next;
//    }
    
    // 获取链表中点
    ListNode* getMid(ListNode* head, ListNode* end){
        if(head == end || head->next == end){
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != end){
            slow = slow->next;
            fast = fast->next;
            if(fast != end){
                fast = fast->next;
            }
        }
        return slow;
    }
    // 归并排序
    ListNode* mergeSort(ListNode* head, ListNode* end){
        // 不包括end，如果有end出现，置空
        if(head == end){
            head = nullptr;
            return head;
        }
        if(head->next == end){
            head->next = nullptr;
            return head;
        }
        
        ListNode* mid = getMid(head, end);
        ListNode* a = mergeSort(head, mid);
        ListNode* b = mergeSort(mid, end);
        ListNode* newHead = new ListNode(0);
        ListNode* cur = newHead;
        while(a != nullptr && b != nullptr){
            if(a->val <= b->val){
                cur->next = a;
                a = a->next;
            } else {
                cur->next = b;
                b = b->next;
            }
            cur = cur->next;
        }
        while(a != nullptr){
            cur->next = a;
            a = a->next;
            cur = cur->next;
        }
        while(b != nullptr){
            cur->next = b;
            b = b->next;
            cur = cur->next;
        }
        return newHead->next;
    }
    ListNode* sortList(ListNode* head) {
        return mergeSort(head, nullptr);
    }
};

int main(){
    int n;
    cin >> n;
    ListNode* head = new ListNode;
    ListNode* cur = head;
    head->next = cur;
    for(int i = 0; i < n; i++){
        int v;
        cin >> v;
        cur->next = new ListNode(v);
        cur = cur->next;
    }
    Solution sol;
    head = sol.sortList(head->next);
    while(head != nullptr){
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}
