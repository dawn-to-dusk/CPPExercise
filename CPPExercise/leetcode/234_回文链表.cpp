//
//  234_回文链表.cpp
//  Tmp
//
//  Created by Baozhu Fang on 2022/8/12.
//

#include<iostream>
#include<stack>
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
    bool isPalindrome(ListNode* head) {
        stack<int> stk;
        ListNode* cur = head;
        while(cur!= nullptr){
            stk.push(cur->val);
            cur = cur->next;
        }
        while(head != nullptr){
            if(head->val != stk.top()){
                return false;
            }
            head = head->next;
            stk.pop();
        }

        return true;
    }
};

int main(){
    int n;
    cin >> n;
    ListNode* head = new ListNode;
    ListNode* pre = head;
    for(int i = 0; i < n; i++){
        int val;
        cin >> val;
        ListNode* cur = new ListNode(val);
        pre->next = cur;
        pre = pre->next;
    }
    
    Solution sol;
    cout << sol.isPalindrome(head->next) << endl;
}
