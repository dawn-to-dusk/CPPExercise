//
//  23_合并升序链表.cpp
//  Tmp
//
// 注意合并的时候尽量直接移动next指针避免创建新节点，可以达到O(1)的空间复杂度
//  Created by Baozhu Fang on 2022/8/13.
//


#include<iostream>
#include<vector>
#include<dequeue>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct cmp{
    bool operator(ListNode* n1, ListNode* n2){
        return n1->val > n2->val;
    }
}

class Solution {
public:
    ListNode* merge(ListNode* a, ListNode* b){
        if(a == nullptr){
            return b;
        }
        if(b == nullptr){
            return a;
        }
        if(a->val > b->val){
            return merge(b, a);
        }
        ListNode* head = a;
        ListNode* cur = head;
        a = a->next;
        while(a != nullptr && b != nullptr){
            if(a->val <= b->val){
                cur->next = a;
                a = a->next;
                cur = cur->next;
            } else {
                cur->next = b;
                b = b->next;
                cur = cur->next;
            }
        }
        if(a != nullptr){
            cur->next = a;
        }
        if(b != nullptr){
            cur->next = b;
        }
        
        return head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0){
            return nullptr;
        }
        ListNode* res = lists[0];
        for(int i = 1; i < lists.size(); i++){
            res = merge(res, lists[i]);
        }
        return res;
    }
    
    
    
    ListNode* mergeKLists_pro(vector<ListNode*>& lists) {
            if(lists.size() == 0){
                return nullptr;
            }
            priority_queue<ListNode*, vector<ListNode*>, cmp> q;
            for(int i = 0; i < lists.size(); i++){
                if(lists[i] != nullptr){
                    q.push(lists[i]);
                }
            }
            
            ListNode* head = new ListNode();
            ListNode* res = head;
            while(!q.empty()){
                ListNode* cur = q.top();
                q.pop();
                res->next = cur;
                if(cur->next != nullptr){
                    q.push(cur->next);
                }
                res = res->next;
            }
            res->next = nullptr;
            return head->next;
    }
};

int main(){
    int n;
    cin >> n;
    vector<ListNode*> lists(n);
    for(int i = 0; i < n; i++){
        int m;
        cin >> m;
        ListNode* head = new ListNode;
        ListNode* cur = head;
        for(int j = 0; j < m; j++){
            int val;
            cin >> val;
            cur->next = new ListNode(val);
            cur = cur->next;
        }
        lists[i] = head->next;
    }
    
    Solution sol;
    ListNode* res = sol.mergeKLists(lists);
    
    while(res != nullptr){
        cout << res->val << " ";
        res = res->next;
    }
    return 0;
}
