//
//  9_回文数.cpp
//  Tmp
//
//  Created by Baozhu Fang on 2022/8/13.
//

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }
        stack<int> stk;
        queue<int> que;
        while(x != 0){
            int val = x % 10;
            stk.push(val);
            que.push(val);
            x = x/10;
        }
        while(!stk.empty()){
            if(stk.top() != que.front()){
                return false;
            }
            stk.pop();
            que.pop();
        }
        return true;
    }
};

int main(){
    int val;
    cin >> val;
    Solution sol;
    cout << sol.isPalindrome(val) << endl;
}
