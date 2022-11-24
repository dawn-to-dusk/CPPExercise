//
//  sizeof_strlen.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/9/16.
//

#include<iostream>
#include<string.h>
using namespace std;

int main(int argc, char const *argv[]){
    const char* str = "name";

    cout << sizeof(str) << endl; // 取的是指针str的长度，是8字节（64位系统）
    cout << sizeof(*str) << endl; // 取的是str字符数组第一个元素的长度，char 1 个字节
    cout << strlen(str) << endl; // 取的是这个字符串的长度，不包含结尾的 \0。大小是4
    
    
    cout << endl;
    char cc[] = "hello";
    cout << sizeof(cc) << endl; // 6 (5+1)
    cout << sizeof(*cc) << endl; // 1
    
    cout << endl;
    char ccc[] = "hello\012";
    cout << sizeof(ccc) << endl; // 7 (5+1)
    cout << sizeof(*ccc) << endl; // 1
      return 0;
}
