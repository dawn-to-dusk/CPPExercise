//
//  栈排序.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/9/16.
//

#include<iostream>
#include<stack>
using namespace std;

void sortStack(stack<int> &nums, int pre){
    if(nums.empty()){
        nums.push(pre);
        return;
    }
    
    int cur = nums.top();
    nums.pop();
    if(pre > cur){
        int tmp = pre;
        pre = cur;
        cur = tmp;
    }
    sortStack(nums, cur);
    nums.push(pre);
}

void printStack(stack<int> nums){
    while(!nums.empty()){
        cout << nums.top() << " ";
        nums.pop();
    }
    cout << endl;
}

int main(){
    stack<int> nums;
    for(int i = 0; i < 5; i++){
        nums.push(i);
    }
    printStack(nums);
    if(nums.empty()){
        return 0;
    }
    for(int i = 0; i < nums.size(); i++){
        int cur =  nums.top();
        nums.pop();
        sortStack(nums, cur);
    }
    
    printStack(nums);
    return 0;
}
