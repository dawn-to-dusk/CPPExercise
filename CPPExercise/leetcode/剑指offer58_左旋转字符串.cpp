//
//  剑指offer58_左旋转字符串.cpp
//  Tmp
//
//  Created by Baozhu Fang on 2022/8/12.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string tmp;
        string tmp1;
        for(int i = 0; i < s.length(); i++){
            if(i < n){
                tmp = tmp + s[i];
            } else {
                tmp1 = tmp1 + s[i];
            }
        }
        return tmp1 + tmp;

    }
};

int main(){
    string str;
    cin >> str;
    int n;
    cin >> n;
    Solution sol;
    cout << sol.reverseLeftWords(str, n) << endl;
}
