//
//  556_下一个更大元素.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/8/29.
//

#include<iostream>
#include<string.h>
using namespace std;

class Solution {
public:
    void nextPermute(string& str){
        int i = str.length() - 2;
        while(i >= 0 && str[i] >= str[i+1]){
            i--;
        }
        
        if(i < 0){
            str = "-1";
            return;
        }
        int j = str.length() - 1;
        while(j > i && str[j] <= str[i]){
            j--;
        }
        swap(str[i], str[j]);
        reverse(str.begin() + i + 1, str.end());
    }
    int nextGreaterElement(int n) {
        string str = to_string(n);
        nextPermute(str);
        long long res = stoll(str);
        if(res > INT_MAX){
            return -1;
        } else {
            return res;
        }
    }
};

int main(){
    int n;
    cin >> n;
    cout << Solution().nextGreaterElement(n) << endl;
    return 0;
}
