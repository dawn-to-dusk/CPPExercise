//
//  1.cpp
//  Test
//
//  Created by Baozhu Fang on 2022/9/13.
//


/*
 小红拿到了一个字符串，她想知道有多少个"baidu"型子串?所谓"baidu"型字符串，指第1个、第4个字母是辅音，第2、3、5个字来是元音，且每个字母都不相同的字符串。例如，"taigu"、"huida"、"paobu"、"baoli"等都是"baidu"型字符串。

 我们定义，元音字母仅有'a'、 'e'、'i'、 'o'、'u'这五种，其余字母均为辅字母。

 输入描述:
 一个仅由小写字母组成的字符串，长度不超过200000。

 输出描述:
 "baidu"型子串的数量。
 
 baiduoxiaojiabankanjiaran
 2
 
 共有"baidu"和"duoxi"这两个baidu型字符串。请注意，"jiaba"和"jiara"并不是baidu型字符串，因为都出现了两个'a '。
 */

#include<iostream>
#include<string.h>
#include<algorithm>
#include<unordered_set>
using namespace std;

const int N = 200010;
string str;

unordered_set<char> cs = {'a', 'e', 'i', 'o', 'u'};
bool check(string str){
    
    unordered_set<char> cur;
    for(int i = 0; i < str.length(); i++){
        if(cur.find(str[i]) != cur.end()){
            return false;
        }
        cur.insert(str[i]);
        if(i == 0 || i == 3){
            if(cs.find(str[i]) == cs.end()){
                continue;
            } else {
                return false;
            }
        } else{
            if(cs.find(str[i]) != cs.end()){
                continue;
            } else {
                return false;
            }
        }
        
    }

    return true;
}

int main(){
    //cin >> str;
    str = "";
    for(int i = 0; i < 200000/5; i++){
        str += "baidu";
    }
    
    int n = 0;
    for(int i = 0; i < str.length() - 4; i++){
        if(check(str.substr(i, 5))){
            n++;
        }
    }
    
    cout << n << endl;
    return 0;
}
