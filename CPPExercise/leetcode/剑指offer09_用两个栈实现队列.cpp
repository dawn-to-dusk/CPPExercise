//
//  剑指offer09_用两个栈实现队列.cpp
//  CPPExercise
//  双栈实现
//
//  Created by Baozhu Fang on 2022/8/10.
//

#include <stdio.h>
#include <iostream>
#include <stack>
using namespace std;

class CQueue {
public:
    stack<int> stkIn;
    stack<int> stkOut;
    CQueue() {
    }
    
    void appendTail(int value) {
        stkIn.push(value);
    }
    
    int deleteHead() {
        if(stkOut.empty()){
            while(!stkIn.empty()){
                int tmp = stkIn.top();
                stkOut.push(tmp);
                stkIn.pop();
            }
            if(stkOut.empty()){
                return -1;
            }
        }
        int res = stkOut.top();
        stkOut.pop();
        return res;
    }
};

int main(){
    CQueue* obj = new CQueue();
    int value;
    cin >> value;
    obj->appendTail(value);
    int param_2 = obj->deleteHead();
    cout << param_2 << endl;
    return 0;
}

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
