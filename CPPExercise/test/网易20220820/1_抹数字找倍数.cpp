//
//  1_抹数字找倍数.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/8/20.
//

/**
 小红拿到了两个正整数a和b，她每次操作可以选择其中个正整数，删除个数位。例如，对于"1243"而言，进行一次操作可以生成"124"、"123"、 "143"或"243"。
 小红希望最终a是b的倍数或者b是a的倍数。她想知道自己最少的操作次数是多少？
 输入2个数a b，其中a,b<=1e9
 输出最少的操作次数。
 
 input:
 1234 99
  
 output:
 2
 */

/**
 数字的长度小于9，可以直接枚举所有的子序列进行比较
 */
#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#include<algorithm>
#include<unordered_set>
using namespace std;


unordered_set<string> aNums;
unordered_set<string> bNums;

void getNums(string str, unordered_set<string> &nums){
    if(str.length() == 1){
        return;
    }
    for(int i = 0; i < str.length(); i++){
        string dst;
        if(i == 0){
            dst = str.substr(1, str.length() - 1);
        } else if(i == str.length() - 1){
            dst = str.substr(0, str.length() - 1);
        } else {
            dst = str.substr(0, i) + str.substr(i + 1, str.length() - i - 1);
        }
        nums.insert(dst);
        getNums(dst, nums);
    }
}

bool check(string aStr, string bStr){
    int a = stoi(aStr);
    int b = stoi(bStr);
    if(a < b){
        return check(bStr, aStr);
    }
    if(a % b == 0){
        return true;
    } else {
        return false;
    }
}

int main(){
    string a, b;
    cin >> a >> b;
    aNums.insert(a);
    getNums(a, aNums);
    bNums.insert(b);
    getNums(b, bNums);
    int minN = INT_MAX;
    for(auto aItem : aNums){
        for(auto bItem : bNums){
            if(check(aItem, bItem)){
                int count = a.length() - aItem.length() + b.length() - bItem.length();
                minN = min(count, minN);
            }
        }
    }
    cout << minN << endl;
    return 0;
}
