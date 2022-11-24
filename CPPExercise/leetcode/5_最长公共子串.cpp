//
//  5_最长公共子串.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/9/22.
//

// 中心扩展法

#include<iostream>
using namespace std;

class Solution {
public:
    string getStr(string s, int l, int r){
        if(r >= s.length()){
            return "";
        }
        while(l >= 0 && r < s.length() && s[l] == s[r]){
            //cout << l << r << endl;
            l--;
            r++;
        }

        return s.substr(l+1, r-l-1);

    }
    string longestPalindrome(string s) {
        string res = "";
        for(int i = 0; i < s.length(); i++){
            string tmp = getStr(s, i, i);
            string tmp1 = getStr(s, i, i+1);
            if(tmp.length() > res.length() && tmp.length() > tmp1.length()){
                res = tmp;
            }
            if(tmp1.length() > res.length() && tmp1.length() > tmp.length()){
                res = tmp1;
            }
        }
        return res;
    }
};
