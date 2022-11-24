//
//  3_字符串替换.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/10/8.
//

/*
 括号中字符替换为*
 如 aaa(bbb)dd(ddd) 替换为 aaa(*)dd(*)
 */

// ak
#include<iostream>
#include<string.h>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param originalStr string字符串 原始字符串
     * @return string字符串
     */
    string ConvertString(string originalStr) {
        // write code here
        int start = 0;
        string res = "";
        for(int i = 0; i < originalStr.length(); i++){
            switch(originalStr[i]){
                case '(':{
                    start++;
                    res = res + '(';
                    break;
                }
                case ')':{
                    start--;
                    res = res + ')';
                    break;
                }
                default:{
                    if(start > 0){
                        if(originalStr[i-1] == '(') res = res + '*';
                    } else {
                        res = res + originalStr[i];
                    }
                    break;
                }
            }
            //cout << originalStr[i] << endl;
        }
        return res;
    }
};
