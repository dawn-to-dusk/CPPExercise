//
//  面试题10_01_合并排序数组.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/9/1.
//
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int a = m - 1;
        int b = n - 1;
        int c = m + n - 1;
        for(; c >= 0; c--){
            if(a >= 0 && b >= 0){
                if(A[a] > B[b]){
                    A[c] = A[a--];
                } else {
                    A[c] = B[b--];
                }
            } else {
                if(a >= 0){
                    A[c] = A[a--];
                } else {
                    A[c] = B[b--];
                }
            }
        }
    }
};
