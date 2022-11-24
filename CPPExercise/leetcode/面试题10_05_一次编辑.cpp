//
//  面试题10_05_一次编辑.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/9/1.
//

#include<iostream>
using namespace std;

class Solution {
public:
    bool oneEditAway(string first, string second) {
        if(first.length() == second.length()){
            int cnt = 0;
            for(int i = 0; i< first.length(); i++){
                if(first[i] == second[i]){
                    continue;
                } else if(cnt == 0){
                    cnt++;
                } else {
                    return false;
                }
            }
        } else {
            if(first.length() < second.length()){
                return oneEditAway(second, first);
            }
            if(first.length() > second.length() + 1){
                return false;
            }
            int cnt = 0;
            for(int i = 0, j = 0; i < first.length(); i++){
                if(first[i] == second[j]){
                    j++;
                    continue;
                } else if (cnt == 0){
                    cnt++;
                    continue;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
