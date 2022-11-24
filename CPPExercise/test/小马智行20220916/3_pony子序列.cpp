//
//  z3.cpp
//  Test
//
//  Created by Baozhu Fang on 2022/9/16.
//

/*
 找出字符串中的pony子串的个数，不一定要连续
 12
 pypypoonyony
 2
 */

// 没来得及提交

#include<iostream>
#include<stack>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;


unordered_map<char, int> um;
void fun(char c, stack<char> &st, stack<char> &tmp){
    while(!st.empty()){
        char cur = st.top();
        st.pop();
        if(cur == c){
            st.pop();
            break;
        }
        tmp.push(cur);
    }
    while(!tmp.empty()){
        st.push(tmp.top());
        tmp.pop();
    }
    um[c]--;
}


int main(){
    int n;
    cin >> n;
    string str;
    cin >> str;
    
    stack<char> st;

    int res = 0;
    for(int i = 0; i < n; i++){
        switch (str[i]) {
            case 'p':
                st.push('p');
                um['p']++;
                break;
            case 'o':
                if(um['p'] > 0){
                    st.push('o');
                    um['o']++;
                }
                break;
            case 'n':
                if(min(um['p'],um['o']) > 0){
                    st.push('n');
                    um['n']++;
                }
                break;
            default:
                if(min(min(um['p'],um['o']), um['n']) > 0){
                res++;
                stack<char> tmp;
                fun('n', st, tmp);
                fun('o', st, tmp);
                fun('p', st, tmp);
                }
                break;
        }
    }
    
    cout << res << endl;
}
