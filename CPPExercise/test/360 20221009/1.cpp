

/*
 n(1<=n<=5000)
 hi(0<=hi<=1000000000)
 
 5
 5 1 2 1 5
 3
 */

#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

const int N = 5010;
int nums[N];
int sum[N];
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin>>nums[i];
    }
    
    if(n < 3){
        cout << 0 << endl;
        return 0;
    }
    if(n == 3){
        if(nums[1] < nums[0] && nums[1] < nums[2]){
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
        return 0;
    }
    
    stack<int> stk;
    for(int i = 0; i < n; i++){
        if(stk.empty() || nums[stk.top()] > nums[i]){
            stk.push(i);
        } else {
            sum[stk.top()] += stk.size() - 1;
            while(!stk.empty()){
                stk.pop();
            }
            stk.push(i);
        }
    }
    
    if(stk.size() > 1){
        sum[stk.top()] += stk.size() - 1;
    }
    while(!stk.empty()){
        stk.pop();
    }
    
    
    for(int i = n-1; i >= 0; i--){
        if(stk.empty() || nums[stk.top()] > nums[i]){
            stk.push(i);
        } else {
            sum[stk.top()] += stk.size() - 1;
            while(!stk.empty()){
                stk.pop();
            }
            stk.push(i);
        }
    }
    
    if(stk.size() > 1){
        sum[stk.top()] += stk.size() - 1;
    }
    
    int res = 0;
    for(int i = 0; i < n; i++){
        res = max(res, sum[i]);
    }
    
    cout << res + 1 << endl;
    return 0;
    
}

