//
//  1_有效数列.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/9/20.
//

/*
 假设给出一个包含n个数的数列，从数列中挑选出一些数，让这些数形成一个新的数列，新的数列如果满足如下3个 要求，则该数列就可以称为『有效数列):
 1、保持原数列中的数的相对顺序不变，且必须都是原数列中连续的;
 2、左右对称，假设有m个数的数列，则第1个数和第 m个数相等第2个数和第m-1个数相等，以此类推，如果m是奇数，则中间那个可以任意;
 3、从左到中间那个数，数需要保证不变小，如果有n个数，则n[1] <=n[2] <= n[3] .… <= n[mid];
 现给出数列，求出该数列满足『有效数列』的最大长度。
 输入描述:
 输入数据第一行包含一个整数T，表示总共有T组测试数据(T<= 20);
 每组数据首先是一个整"n(1 n <=100000)，表示数列的长
 度，接下来一行输入n个整效。表示数列从左到右的值(50<=n[i] <= 250) ;
 输出描述:
 输出有效数列的最大长度，每组占一行
 
 */

/*
 2
 3
 51 52 51
 4
 51 52 52 51
 3
 4
 
 1<n<1000 00
 */

//57% 有点像最长回文子串 以下代码改过，可能有问题

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int N = 1010;
int nums[N];
int n;
int dp[N][N];

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n;
        for(int j = 0; j < n; j++){
            cin >> nums[j];
        }
        
        if(n == 1){
            cout << 1 << endl;
            continue;
        }
        
        int l = 0, r = 1;
//        for(int j = 0; j < n; j++){
//            dp[j][j]=1;
//            if(j < n-1 && nums[j] == nums[j+1]){
//                dp[j][j+1] = 1;
//
//            }
//        }
//
        int cnt = 0;
        int pre = -1;
        while(l < r){
            if(nums[l] < nums[r]){
                l++;
                cnt = 0;
                pre = -1;
            } else if(nums[l] > nums[r]){
                r--;
                cnt = 0;
                pre = -1;
            } else {
                if(pre == -1 || nums[pre] <= nums[l]){
                    pre = l;
                    l++;
                    r--;
                    cnt++;
                }

            }
        }
        cnt = cnt *  2;
        if(l == r && nums[pre] <= nums[l]){
                cnt++;
        }
        
        cout << cnt <<endl;
    }
    
    return 0;
}
