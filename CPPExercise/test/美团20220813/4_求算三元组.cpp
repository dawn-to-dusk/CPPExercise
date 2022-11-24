//
//  4_求算三元组.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/8/13.
//

/**
 求算一个序列中，最多有几个三元组满足
 i<j<k，a[i] - a[j] = 2a[j] - a[k]
 1<=n<=4000, 0<=a[i]<=1000000
 输出符合的数量
 e.g.
 输入：
 4
 4 2 2 2
 输出：
 3
 解释：
 1 2 3
 1 2 4
 1 3 4
 */

// ac %45 超时
//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<map>
//using namespace std;
//
//int main(){
//    int n;
//    cin >> n;
//    vector<int> nums(n);
//    for(int i = 0; i < n; i++){
//        cin >> nums[i];
//    }
//
//    int count = 0;
//    map<int, int> xm;
//
//
//    int x, y, z;
//    for(int i = 0; i < n - 2; i++){
//        x = nums[i];
//        if(xm.find(x) != xm.end() && i < xm[x]){
//            count++;
//            continue;
//        }
//        map<int, int> ym;
//        for(int j = i + 1; j < n - 1 ; j++){
//            y = nums[j];
//            if(ym.find(y) != ym.end() && j < ym[y]){
//                count++;
//                continue;
//            }
//
//            int val = nums[j] * 3 - nums[i];
//            if(val < 0){
//                continue;
//            }
//
//            for(int k = j + 1; k < n; k++){
//                if(nums[k] == val){
//                    count++;
//                    xm[x] = j;
//                    ym[y] = k;
//                }
//            }
//        }
//    }
//
//    cout << count << endl;
//    return 0;
//}


#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

// 没用二分查找的，ac了45%
int search(vector<int> &nums, int k, int left, int right){
    if(left >= right) {
        if(nums[right] == k) {
            return right;
        } else {
            return -1;
        }
    }
    int mid = (left + right) >> 1;
    if(mid < k){
        return search(nums, k, mid + 1, right);
    } else {
        return search(nums, k, left, mid);
    }
    
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    int count = 0;
    map<int, int> xm;
    map<int, int> ym;

    int x, y;
    
    for(int i = 0; i < n - 2; i++){
        bool flagX = false;
        bool flagY = false;
        x = nums[i];
         // 重复的x
        if(xm.find(x) != xm.end()){
            flagX = true;
        }
        if(flagX && i < xm[x]){
            count++;
            continue;
        }
        
        for(int j = i + 1; j < n - 1 ; j++){
            y = nums[j];
            if(ym.find(y) != ym.end()){
                flagY = true;
            }
            // 同一个x 重复的y
            if(flagX && flagY && j < ym[y]){
                count++;
                continue;
            }
            // 不同的x 重复的y
            if(!flagX && flagY){
                continue;
            }

            int val = nums[j] * 3 - nums[i];
            if(val < 0){
                continue;
            }
            
            int res = search(nums, val, j+1, n-1);
            if(res > 0){
                count++;
                xm[x] = j;
                ym[y] = res;
            }
            flagX = true;
        }
    }

    cout << count << endl;
    return 0;
}
