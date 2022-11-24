//
//  剑指offer04_二维数组中的查找.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/8/19.
//

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
//    // 二分查找
//    int mysort(vector<int> nums, int target, int left, int right){
//        if(nums.size() <= 0){
//            return -1;
//        }
//        if(left >= right){
//            return right;
//        }
//        int mid = (left + right) >> 1;
//        if(nums[mid] < target){
//            return mysort(nums, target, mid + 1, right);
//        } else {
//            return mysort(nums, target, left, mid);
//        }
//    }
//    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
//        if(matrix.size() <= 0 || matrix[0].size() <= 0){
//            return  false;
//        }
//        int right = matrix[0].size() - 1;
//        for(int i = 0; i < matrix.size(); i++){
//            int tmp = mysort(matrix[i], target, 0, right);
//            if(tmp == -1){
//                return false;
//            }
//            if(matrix[i][tmp] == target){
//                return true;
//            }
//            right = tmp;
//        }
//        return false;
//    }
    
    
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if(n <= 0){
            return false;
        }
        int m = matrix[0].size();
        int i = 0, j = m - 1;
        while(i < n && j >= 0){
            if(matrix[i][j] < target){
                i++;
            } else if(matrix[i][j] > target){
                j--;
            } else {
                return true;
            }
        }
        return false;
    }
};

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector(m, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> matrix[i][j];
        }
    }
    int t;
    cin >> t;
    Solution sol;
    cout << sol.findNumberIn2DArray(matrix, t) << endl;
}
