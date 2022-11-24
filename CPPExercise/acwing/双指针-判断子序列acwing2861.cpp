//
//  双指针-判断子序列acwing2861.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/7/29.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> A(n);
    vector<int> B(m);
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    for(int i = 0; i < m; i++){
        cin >> B[i];
    }
    
    int j = 0;
    for(int i = 0; i < m; i++){
        if(j < n && B[i] == A[j]){
            j++;
        }
    }
    if(j == n){
        cout << "Yes" <<endl;
    } else {
        cout << "No" << endl;
    }
}
