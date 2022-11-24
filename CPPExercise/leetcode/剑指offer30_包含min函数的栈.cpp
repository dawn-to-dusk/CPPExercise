//
//  剑指offer30_包含min函数的栈.cpp
//  CPPExercise
//  min辅助栈
//
//  Created by Baozhu Fang on 2022/8/10.
//

#include <stdio.h>
#include <iostream>
#include <stack>
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> stkNum;
    stack<int> stkMin;
    MinStack() {
    }
    
    void push(int x) {
        if(stkNum.empty()){
            stkMin.push(x);
        } else {
            stkMin.push(x <= stkMin.top() ? x : stkMin.top());
        }
        stkNum.push(x);
    }
    
    void pop() {
        stkNum.pop();
        stkMin.pop();
    }
    
    int top() {
        return stkNum.top();
    }
    
    int min() {
        return stkMin.top();
    }
};

int main(){
    MinStack* obj = new MinStack();
    int x;
    cin >> x;
    obj->push(x);
    obj->pop();
    int param_3 = obj->top();
    int param_4 = obj->min();
    cout << param_3 << " " << param_4 << endl;
    delete obj;
    return 0;
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */
