/*

 小红拿到了一个01串，她每次可以选择一个长度为2的连续子串取反(0变1，1变0)，她想知道，是否能在有限的操作次数内使得所有字符相同?
 共有q组询问。

 输入描述:
 第一行输入一个正整数q，代表询问次数。
 每次询问输入一个字符串，仅由'0'和'1'组成。所有字符串长度之和不超过200000。

 输出描述:
 对于每次询问，如果该字符串可以通过有限的操作使得所有字符相同，则输出"Yes"，否则输出"No"。


 */

/*
 3
 101
 1111
 1011
 
 Yes
 Yes
 No
 
 第一组询问，先对前两个字符操作，交成"011"，然后对后两个字符操作，变成"000"。
 第二组询问，不需要任何操作。
 第三组询问，显然无法通过有效的操作次效使得所有字符相等。
 */

#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

int n;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        int a = 0;
        int b = 0;
        for(int j = 0; j < str.length(); j++){
            if(str[j] == '1'){
                a++;
            } else {
                b++;
            }
        }
        if(a % 2 != 0 && b % 2 != 0){
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }
    
    return 0;
}

