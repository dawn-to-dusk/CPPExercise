//
//  2131_连接两字母单词得到的最长回文串.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/8/21.
//

#include<iostream>
#include<map>
using namespace std;

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> reverseMap;
        int count = 0;
        for(int i = 0; i < words.size(); i++){
            if(reverseMap.find(words[i]) != reverseMap.end() && reverseMap[words[i]] != 0){
                reverseMap[words[i]]--;
                count += 4;
            } else {
                string rw = string(1, words[i][1])+ words[i][0];
                if(reverseMap.find(rw) == reverseMap.end()){
                    reverseMap[rw] = 1;
                } else {
                    reverseMap[rw]++;
                }
            }
        }
        for(auto [k, v]:reverseMap){
            if(v != 0 && k[0] == k[1]){
                count += 2;
                break;
            }
        }
        return count;
        
    }
};
