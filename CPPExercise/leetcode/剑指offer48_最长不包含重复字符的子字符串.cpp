//
//  剑指offer48_最长不包含重复字符的子字符串.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/8/20.
//

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s){
        if(s.length() == 0){
            return 0;
        }
        int ch[200];
        memset(ch, 0, sizeof(ch));
        int a = 0;
        int maxL = 0;
        for(int i = 0; i < s.length(); i++){
            if(ch[s[i]] != 0){
                while(ch[s[i]] != 0){
                    ch[s[a]]--;
                    a++;
                }
            }
            ch[s[i]]++;
            maxL = max(maxL, i - a + 1);
        }
        return maxL;
    }
};


int main(){
    string str;
    cin >> str;
    Solution sol;
    cout << sol.lengthOfLongestSubstring(str) << endl;
    return 0;
}
