//
//  1_拼接数字.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/9/14.
//

/*
 桌面上有n张卡片，每张卡片上都写有一个正整数，现在你可以从中选出三张卡片，将卡片上的三个数按任意顺序连接成一个新的数。例如，对于三个数字123、45、678，你可以将它们连成12345678、45123678、67845123、67812345或12367845等，可以证明67845123是能拼接出的最大的数。注意，对于卡片上的数字，你不能将其拆开。
 
 输入描述
 第一行是一个正整数n，表示有n张卡片。
 第二行是n个用空格隔开的正整数，其中第i个数a_i表示第i张卡片上写的数字。保证数字不含前导零。
 输出描述
 一行一个整数，表示能拼接出的最大的数。
 
 4
 123 45 678 23
 67845123
 
 1<=n<=100000, 1<=ai<=20000000
 */

// ak

#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;

const int N = 100000;
int n;
vector<string> nums;

bool cmp(const string &a, const string &b){
    if(a.length() != b.length()){
        return a.length() > b.length();
    } else{
        return a > b;
    }
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        nums.emplace_back(str);
    }
    
    sort(nums.begin(), nums.end(), cmp);
    vector<string> cur;
    for(int i= 0; i < 3; i++){
        cur.emplace_back(nums[i]);
    }
    sort(cur.begin(), cur.end());
    for(int i= 2; i >= 0; i--){
        cout << cur[i];
    }
    cout << endl;
    return 0;
}
