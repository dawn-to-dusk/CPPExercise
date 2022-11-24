//
//  字符串数组.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/8/23.
//

#include<iostream>
using namespace std;

int main(){
    char str1[] = "abc";
    char str2[] = "abc";
    const char str3[] = "abc";
    const char str4[] = "abc";
    const char *str5 = "abc";
    const char *str6 = "abc";
    // == 取的是字符数组的地址
    // 数组对象存储在栈空间，对应不同的栈地址
    // 指针对象实际是将"abc"常量存储到常量区，再用指针指向常量，所有两个指针指向相同地址
    
    // 数组对象用&可以取地址
    // 指针对象由于系统对字符指针做了重载，这里将指针转换为其他类型，即可以打印出地址
    cout << (str1 == str2) << " " << &str1 << " " << &str2 << endl;
    cout << (str3 == str4) << " " << &str3 << " " << &str4 << endl;
    cout << (str5 == str6) << " " << (void *)str5 << " " << (void*)str6 << endl;
}
