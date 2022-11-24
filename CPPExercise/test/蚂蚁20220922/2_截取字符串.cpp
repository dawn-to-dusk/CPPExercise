//
//  2.cpp
//  Test
//
//  Created by Baozhu Fang on 2022/9/22.
//

/*
 小红拿到了一个数字串(由'1-9·组成，不含'0’)，她准备截取一段连续子串，使得该子串表示的正整数小于k。你能帮她求出有多少种数取方案吗?
 输入描述:
 第一行输入一个数字串，长度不超过200000。
 第二行输入一个正整数k。1≤k≤1e9
 输出描述:
 小于k的截取方案数。
 */

/*
 1234
 23
 
 5
 // 1 2 3 4 12 五种
 */

#include<iostream>
#include<algorithm>
using namespace std;

string str;
int k;

string getL(int k){
    //int cnt = 0;
    string res = "";
    while(k > 0){
        res += ('0' + k % 10);
        k = k / 10;
        //cnt++;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main(){
    cin >> str >> k;
    int l = str.length();
    string kStr = getL(k);
    int kl = kStr.length();
    int res = 0;
    for(int i = 1; i < kl; i++){
        res += (l-i+1);
    }
    
    if(kl > l){
        res++;
    } else {
        for(int i = 0; i < l - kl + 1; i++){
            for(int j = 0; j < kl; j++){
                if(str[i+j] == kStr[j]){
                    continue;
                } else if (str[i+j] > kStr[j]){
                    break;
                } else {
                    res++;
                    break;
                }
            }
        }
    }
    
    cout << res << endl;
    return 0;
}

