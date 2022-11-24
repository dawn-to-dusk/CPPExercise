//
//  4_字符串中的V形三元组.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/8/20.
//

/**
小红拿到了一个数组 a1....an，她想知道有多少组（i, j, k）为"v三元组"：第一个数和第三个数相等。且第一个数大于第二个数。
 用数学语言描述：
 1<=i<j<k<=n 且 ai==ak 且 ai>aj
 输入n<1e5， ai<=1e9。
 
 input:
 6
 3 1 3 4 3 4
  
 output:
 3
 */



#include<iostream>
#include<algorithm>
#include<vector>
#include<stdlib.h>
using namespace std;

int L[100000][10];
int R[100000][10];

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
   
    for(int i = 0; i < n; i++){
        cin >> nums[i];
        memset(L[i], 0, sizeof(L[i]));
        memset(R[i], 0, sizeof(R[i]));
    }
    
    //L[0][nums[0]]++;
    for(int i = 1; i < n; i++){
        L[i][nums[i-1]]++;
        for(int j = 0; j <= 9; j++){
            L[i][j] += L[i-1][j];
        }
    }
    
    for(int i = n-2; i >= 0; i--){
        R[i][nums[i+1]]++;
        for(int j = 0; j <= 9; j++){
            R[i][j] += R[i+1][j];
        }
    }
    
    int count = 0;
    for(int i = 1; i < n - 1; i++){
        for(int j = nums[i] + 1; j <= 9; j++){
            count += L[i][j] * R[i][j];
        }
    }
    
    cout << count << endl;
    return 0;
    
    
    return 0;
}
