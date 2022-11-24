//
//  2_格式检查.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/8/20.
//

/**
 检查字符串是否符合特定格式
 第一个字符是key，一个小写字母
 第二个是=
 第三个及以后是value，只能包含小写字母、数字及空格，开头不能是空格
 
 （相似用例，非原题用例）
 输入：“k=1" 输出：true
 输入：“k=1 2" 输出：true
 输入："k= 2" 输出：false
 */
#include<iostream>
#include<cmath>
#include<vector>
#include<map>
using namespace std;

bool signalVerify(string signal) {
    // write code here
    if(signal.length() < 3){
        return false;
    }
    if(signal[0] < 'a' || signal[0] > 'z'){
        return false;
    }
    if(signal[1] != '='){
        return false;
    }
    if(signal[2] == ' '){
        return false;
    }
    for(int i = 2; i < signal.length(); i++){
        if(signal[i] == ' '){
            continue;;
        } else if(signal[i] >= '0' && signal[i] <= '9'){
            continue;;
        } else if(signal[i] >= 'a' && signal[i] <= 'z'){
            continue;;
        } else {
            return false;
        }
    }
    return true;
}

int main(){
    string str;
    cin >> str;
    cout << signalVerify(str) << endl;
}
