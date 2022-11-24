//
//  剑指offer35_复杂链表的复制.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/8/11.
//

#include <stdio.h>
#include <iostream>
#include <map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution{
public:
    map<Node*, Node*> nodeM;
    
    Node* copyRandomList(Node* head) {
        if(head == nullptr){
            return nullptr;
        }
        
        if(nodeM.find(head) == nodeM.end()){
            Node* cur = new Node(head->val);
            nodeM[head] = cur;
            cur->next = copyRandomList(head->next);
            cur->random = copyRandomList(head->random);
        }
        
        return nodeM[head];
    }
};
