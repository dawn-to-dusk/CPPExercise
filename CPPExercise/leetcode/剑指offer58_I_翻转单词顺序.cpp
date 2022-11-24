//
//  剑指offer58_I_翻转单词顺序.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/8/31.
//

#include<iostream>
#include<stack>
#include<string.h>
using namespace std;

class Solution {
public:
    
    string reverseWords(string s){
        reverse(s.begin(), s.end());
        int start = 0;
        while(s[start] == ' '){
            s = s.substr(1, -1);
        }
        int end = 0;
        while(start < s.length() && s[start] != ' '){
            while(end < s.length() && s[end] != ' '){
                end++;
            }
            reverse(s.begin() + start, s.begin() + end);
            
        }
    }
    
    
    string reverseWords1(string s) {
        while(s[0] == ' '){
            s = s.substr(1, s.length() - 1);
        }
        
        stack<string> st;
        while(s != ""){
            int pos = s.find(' ');
            string str = s.substr(0, pos);
            st.push(str);
            
            if(pos == -1){
                s = "";
            } else {
                s = s.substr(pos + 1, s.length() - pos - 1);
                while(s[0] == ' '){
                    s = s.substr(1, s.length() - 1);
                }
            }
        }
        
        string res;
        if(!st.empty()){
            res = st.top();
            st.pop();
        }
        while(!st.empty()){
            res = res + " " + st.top();
            st.pop();
        }
        return res;

    }
};

int main(){
    string str = "hello    world hi";
    cout << Solution().reverseWords(str) << endl;
    return 0;
}
