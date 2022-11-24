//
//  12_整数转罗马数字.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/8/24.
//

#include<iostream>
using namespace std;

class Solution {
public:
    int N[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string S[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    string intToRoman(int num) {
        string str;
        while(num > 0){
            for(int i = 0; i < 13; i++){
                if(num - N[i] >= 0) {
                    str = str + S[i];
                    num -= N[i];
                    break;
                }
            }
        }

        return str;
    }
};
