//
//  1_好子数组的数量.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/8/31.
//

/*
 现在一个数组被定义为好的，如果该数组中的最大值是最小值的k倍。现在给你一个数组，你的任务是计算有多少个子数组是好的。
 其中，子数组定义为原数组中一段连续的数组。例如:[4,3,2,7]有以下几个子数组:
 [4],[4,3],[4,3, 2],[4,3, 2, 7],[3],[3,2],[3,2,7],[2],[2,7],[7]
 当k=2时，答案为1，只有[4,3,2]是好数组，它的最大值是4，最小值是2，满足题意。
 1<=n, k <= 1000
 对于全体数据都保证数组中的数字在[1,1e°]范围内
 
 输入描述
 第一行是一个正整数n，k，表示数组长度为n，好数组中最大值是最小值的k倍。
 第二行是n个以空格分开的正整数。依次表示这个数组中的数字。
 输出描述
 一行一个非负整数，表示这个数组有几个子数组是好的。

 input:
 4 2
 4 3 2 7
 output:
 1
 
 input:
 4 3
 3 9 3 9
 output:
 6
 
 input:
 2 1
 2 2
 output:
 3
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define  N 1010

int n, k;
vector<int> nums;
int maxN[N][N];
int minN[N][N];

int main(){
    cin >> n >> k;
    nums.resize(n);
    for(int i = 0;i < n; i++){
        cin >> nums[i];
        maxN[i][i] = nums[i];
        minN[i][i] = nums[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            maxN[i][j] = max(maxN[i][j-1], nums[j]);
            minN[i][j] = min(minN[i][j-1], nums[j]);
        }
    }
    
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            if(maxN[i][j] / minN[i][j] == k && maxN[i][j] % minN[i][j] == 0){
                cnt++;
            }
        }
    }
    
    cout << cnt << endl;
    return 0;
}
