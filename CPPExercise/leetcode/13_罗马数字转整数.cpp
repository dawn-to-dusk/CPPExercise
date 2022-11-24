//
//  13_罗马数字转整数.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/8/24.
//

#include<iostream>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int num = 0;
        for(int i = 0; i < s.length(); i++){
            switch(s[i]){
                case 'I':{
                    if(i < s.length() - 1){
                        if(s[i+1] == 'V') {
                            num += 4;
                            i++;
                            break;
                        } else if (s[i+1] == 'X'){
                            num += 9;
                            i++;
                            break;
                        }
                    }
                        num += 1;
                        break;
                    
                }
                case 'V':{
                    num += 5;
                    break;
                }
                case 'X':{
                    if(i < s.length() - 1){
                        if(s[i+1] == 'L') {
                            num += 40;
                            i++;
                            break;
                        } else if (s[i+1] == 'C'){
                            num += 90;
                            i++;
                            break;
                        }
                    }
                        num += 10;
                        break;
                    
                }
                case 'L':{
                    num += 50;
                    break;
                }
                case 'C':{
                    if(i < s.length() - 1){
                        if(s[i+1] == 'D') {
                            num += 400;
                            i++;
                            break;
                        } else if (s[i+1] == 'M'){
                            num += 900;
                            i++;
                            break;
                        }
                    }
                        num += 100;
                        break;
                    
                }
                case 'D':{
                    num += 500;
                    break;
                }
                case 'M':{
                    num += 1000;
                    break;
                }
            }
        }
        return num;

    }
};
