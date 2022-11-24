//
//  剑指offer50_第一个只出现一次的字符.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/8/19.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    char firstUniqChar(string s) {
        int num[26];
        memset(num, 0, sizeof(num));
        for(int i = 0; i < s.length(); i++){
            num[s[i]-'a']++;
        }
        for(int i = 0; i < s.length(); i++){
            if(num[s[i]-'a'] == 1){
                return s[i];
            }
        }
        return ' ';
    }
};

int main(){
    string str;
    cin >> str;
    Solution sol;
    cout << sol.firstUniqChar(str) << endl;
}
