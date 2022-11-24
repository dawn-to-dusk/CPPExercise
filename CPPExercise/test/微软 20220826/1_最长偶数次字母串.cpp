/**
 英文浏览器直接翻译：
 一条线上有N个点，编号从0到N-1，其坐标在数组A中给出。对于每个10sl<N)，线上点号|的坐标为 A[].点的坐标不必是不同的。
       整数解(字符串 &S);
 例如，考虑整数M=3和数组A使得:
 例子:
 包含编号为1、2、5和6的点(坐标分别为-2、1、7和1)的子集是3对齐子集的示例，因为:
 2.给定S="abacb"，函数应该返回 0。不存在每个字母出现偶数次的非空子字符串。
 并且这些距离都可以被M=3整除。这个子集的大小是4，并且没有更大的3-aligned 子集。
 
 写一个函数:以下假设的有效算法:
 - N是[1..100,000]范围内的整数;
 - 字符串 s仅由小写字母('a-'z') 组成。
 */
#include<iostream>
#include<string.h>
#include<unordered_map>
using namespace std;


bool check(string str, int l, int r, unordered_map<char, int> um){
    for(int i = l; i <= r; i++){
        if(um[str[i]] % 2 != 0){
            return false;
        }
    }
    return true;
}

int getStr(string str, int l, int r, unordered_map<char, int> um){
    if(l >= r){
        return 0;
    }
    
    if(check(str, l, r, um)){
        return r - l + 1;
    } else {
        um[str[l++]]--;
        int x = getStr(str, l--, r, um);
        um[str[l]]++;
        
        um[str[r--]]--;
        int y = getStr(str, l, r++, um);
        um[str[r]]++;
        return max(x, y);
    }
}


int solution(string &S) {
    // write your code in C++ (C++14 (g++ 6.2.0))
    
    unordered_map<char, int> um;
    for(int i = 0; i < S.length(); i++){
        um[S[i]]++;
    }
    
    //cout << getStr(S, 0, S.length() - 1, um) << endl;
    return getStr(S, 0, S.length() - 1, um);
}


int main(){
    string str;
    cin >> str;
    cout << solution(str) << endl;
    return 0;
}

