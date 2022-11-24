//
//  202_快乐数.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/8/12.
//

#include <stdio.h>
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    map<int, bool> numM;
    int getSum(int n){
        int sum = 0;
        while(n){
            int tmp = n%10;
            sum += tmp * tmp;
            n = n/10;
        }
        return sum;
    }
    bool isHappy(int n) {
        if(numM.find(n) != numM.end()){
            return false;
        }
        if(n == 1){
            return true;
        }

        int sum = getSum(n);
        numM[n] = true;
        return isHappy(sum);
    }
};

int main(){
    int n;
    cin >> n;
    Solution sol;
    cout << sol.isHappy(n) << endl;
}
