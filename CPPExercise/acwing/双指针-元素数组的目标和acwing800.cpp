//
//  双指针-元素数组的目标和acwing800.cpp
//  CPPExercise
//
// 核心思想：
// 1.先想暴力算法
// 2.找出单调性，使用双指针
//
//  Created by Baozhu Fang on 2022/7/29.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> A(n);
    vector<int> B(m);
    for(int i = 0; i< n; i++){
        cin >> A[i];
    }
    for(int j = 0; j < m; j++){
        cin >> B[j];
    }
    
    for(int i = 0, j = m - 1; i < n; i++){
        while(A[i] + B[j] >= x) {
            if(A[i] + B[j] == x){
                cout << i << " " << j << endl;
                return 0;
            }
            j--;
        }
    }
    
    return 0;
}
