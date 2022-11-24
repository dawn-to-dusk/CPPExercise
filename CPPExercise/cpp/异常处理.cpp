//
//  异常处理.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/9/11.
//

#include<iostream>
#include<string>
using namespace std;

// 输入2输出"**", ?行填空
// string("**")
// string("*")
// "**"  // 这种对应catch(const char* &e)
// "*"

void f(int s){
    try{
        if(s < 10){
            throw string("*"); // ?
        }
    }catch(string s){
        cout << s;
        throw;
    }
    cout << "#";
}

int main(){
    int i;
    cin >> i;
    try{
        f(i);
    }catch(string s){
        cout << s << endl;
    }
    return 0;
}
