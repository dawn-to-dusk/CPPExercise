//
//  整型字符串相加.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/9/11.
//

#include<iostream>
using namespace std;

int main(){
    cout << 1 + 'a' <<endl;
    cout << 'a' + 1 << endl;
    char c = 'a';
    char cc = c + 1;
    string str = "" + c + cc;
    cout << str << endl;
    return 0;
}
