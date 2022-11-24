//
//  2_奇怪的计算器.cpp
//  Test
//
//  Created by Baozhu Fang on 2022/9/2.
//

#include<iostream>
#include<vector>
using namespace std;

int main(){
    string str;
    cin >> str;
    bool flag = true;
    int ans = 0;
    int res = 0;
    for(int i = 0; i< str.size(); i++){
        switch (str[i]) {
            case '+':
            {
                if(flag){
                    res += ans;
                } else {
                    res -= ans;
                }
                flag = true;
                ans = 0;
                break;
            }
                
            case '-':
            {
                if(flag){
                    res += ans;
                } else {
                    res -= ans;
                }
                flag = false;
                ans = 0;
                break;
            }
            case '^':
            {
                i++;
                string tmp1 = "";
                while(i+1 < str.size() && str[i + 1] != '+' && str[i+1] != '-' && str[i+1] != '^'){
                    tmp1 = tmp1 + str[i];
                    i++;
                }
                tmp1 = tmp1 + str[i];
                int ans1 = stoi(tmp1);
                ans = ans ^ ans1;
                break;
            }
            default:
            {
                string tmp = "";
                while(i+1 < str.size() && str[i + 1] != '+' && str[i+1] != '-' && str[i+1] != '^'){
                    tmp = tmp + str[i];
                    i++;
                }
                tmp = tmp + str[i];
                ans = stoi(tmp);
                break;
            }
        }
    }
    
    if(flag){
        res += ans;
    } else {
        res -= ans;
    }
    
    cout << res << endl;
    
    return 0;
}

