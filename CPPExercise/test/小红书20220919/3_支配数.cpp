//
//  3_支配数.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/9/19.
//

/*
 小A认为如果在数组中有一个数出现了至少k次且这个数是该数组的众数(即出现次数最多的数之一)那么这个数组被该数所支配。显然，当k比较大的时候有些数组不被任何数所支配。现在小A想知道她所拥有的数组A中有多少个区间是被某个数所支配的。

 输入描述
 第一行有两个正整数n,k(2<=k<=n<=100000)。n代表小A所拥有的数组A的长度，k代表问题描述中的参数。
 第二行有n个正整数，代表A中元素的值。值的范围在1到n之间。

 输出描述
 输出一个非负整数，代表所求的答案。
 
 6 2
 1 2 1 3 2 3
 8
 输出一个非负整数，代表所求的答案。
 输入中[1,2,1] [1,2,1,3] [1,2,1,3,2] [1,2,1,3,2,3] [2,1,3,2][2,1,3,2,3] [1,3,2,3] [3,2,3]这8个区间均被分别被某些数所支配。
 */


#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<queue>
using namespace std;

const int N = 100010;
int nums[N];
int n, k;
unordered_map<int, int> um;
priority_queue<int> q;

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    
    int cnt = 0;
    int pos = 0;
    for(int i = 0; i < n-k; i++){
        while(um[nums[pos-1]] < k){
            um[nums[pos]]++;
            pos++;
        }
        cnt += (n-pos + 1);
        um[nums[i]]--;
        
    }
    
    
    cout << cnt << endl;
    return 0;
}
