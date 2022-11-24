//
//  归并排序迭代.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/9/16.
//

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void mergeSort(vector<int> &nums){
    int n = nums.size();
    vector<int> tmp(n);
    for(int i = 1; i < n; i *= 2){
        for(int j = 0; j < n; ){
            int l1 = j;
            int l2 = l1 + i;
            int r1 = l2;
            int r2 = min(r1 + i, n);
            while(l1 < l2 && r1 < r2){
                if(nums[l1] <= nums[r1]){
                    tmp[j++] = nums[l1++];
                } else {
                    tmp[j++] = nums[r1++];
                }
            }
            
            while(l1 < l2){
                tmp[j++] = nums[l1++];
            }
            while(r1 < r2){
                tmp[j++] = nums[r1++];
            }
        }
        
        nums.swap(tmp);
    }
}


int main(){
    vector<int> nums = {5, 4, 3, 2};
    mergeSort(nums);
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}
