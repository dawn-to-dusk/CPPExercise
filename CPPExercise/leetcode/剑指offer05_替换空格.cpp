//
//  剑指offer05_替换空格.cpp
//  Tmp
//
//  Created by Baozhu Fang on 2022/8/12.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        string str="";
        for(int i = 0; i < s.length(); i++){
            if(s[i] != ' '){
                str = str + s[i];
            } else {
                str = str + "%20";
            }
        }

        return str;
    }
};

