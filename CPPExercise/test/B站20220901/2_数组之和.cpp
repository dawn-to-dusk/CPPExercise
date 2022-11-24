//
//  t1.cpp
//  Test
//
//  Created by Baozhu Fang on 2022/9/1.
//

#include<iostream>
#include<vector>
using namespace std;

long long func(long long x, long long y, int n){
    for(int i = 0; i < n; i++){
        x += y;
    }
    return x;
}

int main(){
    int n;
    cin >> n;
    vector<long long> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    
    int q;
    cin >> q;
    
    long long add;
    cin >> add;
    long long res = 0;
    for(int i = 0; i < n; i++){
        nums[i] += add;
        res += nums[i];
    }
    if(res < 0){
        cout << - res << endl;
    } else {
        cout << res << endl;
    }
    
    for(int i = 0; i < q - 1; i++){
        cin >> add;
        res = func(res, add, n);
//        res = res + add * n;
        if(res < 0){
            cout << - res << endl;
        } else {
            cout << res << endl;
        }
    }
    return 0;
}

