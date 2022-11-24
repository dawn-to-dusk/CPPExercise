//
//  小猿的纸条.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/8/26.
//

#include<iostream>
#include<unordered_map>
#include<string.h>
using namespace std;

int getNum(string s1, string s2, string s3){
    string tmp = s1 + "_" + s2;
    int res = 0;
    
    
    while(s3 != ""){
        int r = -1;
        string str;
        while(tmp.find(str) != string::npos){
            r++;
            if(r >= s3.length()){
                break;;
            }
            str = str + s3[r];
        }
        str = str.substr(0, r);
        int pos = tmp.find(str);
        if(pos != string::npos){
            res++;
            tmp = tmp.substr(0, pos) + tmp.substr(pos + str.length(), tmp.length() - pos - str.length());
            s3 = s3.substr(r, s3.length() - r);
        } else {
            return -1;
        }
    }
        
    
    return res;
}

int main(){
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        string s1, s2, s3;
        int k;
        cin >> s1 >> s2 >> s3 >> k;
        
        int minN = getNum(s1, s2, s3);
        if(minN <= k && minN > 0){
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
        
    }
    return 0;
}
