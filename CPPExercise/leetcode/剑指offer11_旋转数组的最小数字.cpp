//
//  剑指offer11_旋转数组的最小数字.cpp
//  CPPExercise
//  二分查找
//  Created by Baozhu Fang on 2022/8/19.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& numbers, int left, int right){
        if(left >= right){
            return numbers[left];
        }
        int mid = (left + right) >> 1;
        if(numbers[mid] < numbers[numbers.size() - 1]){
            return search(numbers, left, mid);
        } else if(numbers[mid] > numbers[numbers.size() - 1]){
            return search(numbers, mid + 1, right);
        } else {
            int a = search(numbers, left, mid);
            int b = search(numbers, mid + 1, right);
            if( a < b){
                return a;
            } else {
                return b;
            }
        }
    }
    int minArray(vector<int>& numbers) {
        return search(numbers, 0, numbers.size() - 1);
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    Solution sol;
    cout << sol.minArray(nums) << endl;
}
