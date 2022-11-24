//
//  3.cpp
//  Test
//
//  Created by Baozhu Fang on 2022/9/22.
//

/*
 小红想让你构造一个n行n列的矩阵，矩阵中的元素为1到n^，每个数只出现一次，小红希望每2*2的子矩阵中的元素之和均为奇数，你能帮她吗?
 输入描述:
 一个正整数n。
 1 ≤ n ≤ 100
 输出描述:
 如果无解，直接输出-1即可。
 否则输出n行，每行输出n个正整数，有多解时输出任意合法解。
 */


/*
 3
 
 1 3 2
 7 4 6
 9 5 8
 
 2
 
 -1
 
 1 <= n <= 100
 */

// 过了%73

#include<iostream>
#include<vector>
using namespace std;

int n;

int main(){
    cin >> n;
    if(n == 2){
        cout << -1;
        return 0;
    }
    vector<int> nums[2];
    for(int i = 1; i <= n*n; i++){
        nums[i%2].emplace_back(i);
    }
    
    vector<vector<int> > res(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        res[0][i] = nums[1].back();
        nums[1].pop_back();
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int pre = res[i-1][j] % 2;
            res[i][j] = nums[pre^1].back();
            nums[pre^1].pop_back();
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}

