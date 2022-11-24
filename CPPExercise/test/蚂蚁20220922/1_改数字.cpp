//
//  1.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/9/22.
//

/*
 小红拿到了一个仅由正整数组成的数组，她有以下两种操作
 1.输入1ix，代表将第i个正整数修改为x。
 2.输入2ix，代表查询前i个正整数有多少个数等于x。
 输入描述:
 第一行输入两个正整数n和q，代表数组长度和操作次数。
 第二行输入n个正整数ai，代表初始的数组。
 接下来的q行，每行输入三个正整数op,i，x，用空格隔开，其中op代表操作的类型，i和x的含义见题目描述。
 1≤n,q,ai,x ≤ 200
 1≤op≤ 2
 l<i≤n
 保证至少有1次询问操作。

 输出描述:
 对于每次询问，输出一个整数，代表查询的结果。
 */

/*
 5 3
 1 2 3 4 5
 2 3 1
 1 1 2
 2 3 1
 
 1 0
 */

// ak

#include<iostream>
#include<vector>
using namespace std;

int n, q;
int nums[210];

int main(){
    cin >> n >> q;
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    for(int i = 0; i < q; i++){
        int op, ii, x;
        cin >> op >> ii >> x;
        if(op == 1){
            // 改
            nums[ii-1] = x;
        } else {
            // 查
            int cnt = 0;
            for(int j = 0; j < ii; j++){
                if(nums[j] == x){
                    cnt++;
                }
            }
            cout << cnt << endl;
        }
    }
    
    return 0;
}
