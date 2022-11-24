//
//  14_最长公共前缀.cpp
//  Tmp
//
//  Created by Baozhu Fang on 2022/8/12.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string str = strs[0];
        if(strs.size() <= 1){
            return str;
        }

        int maxN = str.length();
        for(int i = 1; i < strs.size(); i++){
            int cur = 0;
            int j;
            for(j = 0; j < strs[i].length(); j++){
                // 原序列结束
                if(cur >= str.length()){
                    maxN = min(maxN, cur);
                    break;
                }

                if(str[cur] == strs[i][j]){
                    cur++;
                } else {
                    maxN = min(maxN, cur);
                    break;
                }
            }
            if(j == strs[i].length()){
                maxN = min(maxN, cur);
            }
        }

        return str.substr(0, maxN);
    }
};

int main(){
    Solution sol;
    int n;
    cin >> n;
    vector<string> strs(n);
    for(int i = 0; i < n; i++){
        cin >> strs[i];
    }
    
    string res = sol.longestCommonPrefix(strs);
    cout << res << endl;
    return 0;
    
}
