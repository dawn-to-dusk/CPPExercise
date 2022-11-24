//
//  43_字符串相乘.cpp
//  Tmp
//
//  Created by Baozhu Fang on 2022/8/12.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> getNum(string num){
        vector<int> N;
        for(int i = num.length() - 1; i >= 0; i--){
            N.push_back(num[i] - '0');
        }
        return N;
    }
    
    vector<int> add(vector<int> num1, vector<int> num2){
//        while(num1.size() != 1 && num1[num1.size()-1] == 0){
//            num1.pop_back();
//        }
//        while(num2.size() != 1 && num2[num2.size()-1] == 0){
//            num2.pop_back();
//        }
        if(num2.size() > num1.size()){
            return add(num2, num1);
        }
        
        vector<int> res;
        int extra = 0; // 进位
        int i;
        for(i = 0; i < num2.size(); i++){
            extra = extra + num1[i] + num2[i];
            res.push_back(extra % 10);
            extra = extra / 10;
        }
        while(i < num1.size()){
            extra = extra + num1[i];
            res.push_back(extra % 10);
            extra = extra / 10;
            i++;
        }
        if(extra != 0){
            res.push_back(extra);
        }
        
        return res;
    }
    
    vector<int> mul(vector<int> num1, vector<int> num2){
//        while(num1.size() != 1 && num1[num1.size()-1] == 0){
//            num1.pop_back();
//        }
//        while(num2.size() != 1 && num2[num2.size()-1] == 0){
//            num2.pop_back();
//        }
        vector<int> res;
        vector<int> tmp;
        for(int i = 0; i < num1.size(); i++){
            int extra = 0; // 进位
            for(int j = 0; j < i; j++){
                tmp.push_back(0);
            }
            for(int j = 0; j < num2.size(); j++){
                extra = extra + num1[i] * num2[j];
                tmp.push_back(extra % 10);
                extra = extra / 10;
            }
            if(extra != 0){
                tmp.push_back(extra);
            }
            res = add(res, tmp);
            tmp.clear();
        }
        
        return res;
    }
    string multiply(string num1, string num2) {
        vector<int> A = getNum(num1);
        vector<int> B = getNum(num2);
        
        vector<int> res = mul(A, B);
        while(res.size() != 1 && res[res.size()-1] == 0){
            res.pop_back();
        }
        string str = "";
        for(int i = res.size() - 1; i >= 0; i--){
            str += '0' + res[i];
        }
        return str;
    }
};


int main(){
    string a, b;
    cin >> a >> b;
    Solution sol;
    cout << sol.multiply(a, b) << endl;
}
