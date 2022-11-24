//
//  3_尽量多的好e.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/8/20.
//

/**
 小红拿到了一个仅由r'、'e'、'd'组成的字符串， 她定义一个字符'e'为"好e"当 且仅当这个'e'字符既和r相邻也和'd'相邻。 例如"reeder"只有一个"好e"，前 两个'e'都不是"好e"，只有第三个'e'是"好e"。
 小红每次可以修改一个字符（可以将任意字符修改）为任意字符，即三种类型的字符可以相互修改） ，她希望最终"好e"的数量尽可能多。小红想知道，自己最少要修改多少次？
 输入一个只有red三中字符的字符串，长度<2e5。
 输出最小修改次数
 
 input:
 derrd
  
 output:
 1
 */

/**
 因为字符可以随意改，要让结果尽可能的符合要求，因此结果是确定的
 直接确定结果进行比较即可
 */

#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

void getOddDst(string &str, int n){
    for(int i = 1; i < n; i++){
        switch (str[i-1]) {
            case 'r':
            case 'd':
                str = str + "e";
                break;
            default: // 'e'
                if(str[i-2] == 'r'){
                    str = str + "d";
                } else {
                    str = str + "r";
                }
                break;
        }
    }
    return;
}

int check(string a, string b){
    int count = 0;
    for(int i = 0; i < a.size(); i++){
        if(a[i] != b[i]){
            count++;
        }
    }
    return count;
}

int handleOdd(string str){
    string dst1 = "r";
    string dst2 = "d";
    getOddDst(dst1, str.length());
    getOddDst(dst2, str.length());
    int n1 = check(dst1, str);
    int n2 = check(dst2, str);
    return n1 > n2 ? n2 : n1;
}

int main(){
    string str;
    cin >> str;
    if(str.length() % 2 != 0){
        cout << handleOdd(str) << endl;
    } else {
        int n1 = handleOdd(str.substr(0, str.length() - 1));
        int n2 = handleOdd(str.substr(1, str.length() - 1));
        cout <<  (n1 > n2 ? n2 : n1) << endl;
    }
    return 0;
}
