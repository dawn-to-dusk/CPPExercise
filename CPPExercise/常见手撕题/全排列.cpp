//
//  全排列.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/8/28.
//

#include<iostream>
using namespace std;

// 所有元素全排列
void permute(string str, int k){
    if(k == str.size() - 1){
        cout << str << endl; // k是最后一个字符串，当前情况枚举完
    } else if(k >= str.size()){
        return; // k超出范围
    }
    
    // 将str的第k位和后面的每一位交换位置
    for(int i = k; i < str.size(); i++){
        swap(str[k] , str[i]);
        permute(str, k+1);
        swap(str[k] , str[i]);
    }
}
// 部分元素全排列
void permute(string str, int k, int n){
    if(n == 0){
        cout << str.substr(0, k) << endl;
    }
    for(int i = k; i < str.size(); i++){
        swap(str[i], str[k]);
        permute(str, k + 1, n - 1);
        swap(str[i], str[k]);
    }
}

int main(){
    string str;
    cin >> str;
    if(str.empty()){
        return 0;
    }
    cout << "全排列" << endl;
    permute(str, 0);
    cout << "n个排列" << endl;
    int n;
    cin >> n;
    permute(str, 0, n);
    return 0;
}
