//
//  735_行星碰撞.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/9/16.
//

#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;


class Solution {
public:

    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        
        for(int i = 0; i < asteroids.size(); i++){
            if(asteroids[i] > 0){
                st.push_back(asteroids[i]);
                continue;
            }

            bool flag = true;
            while(!st.empty()){
                if(st[st.size()-1] > 0){
                    if(st[st.size()-1] > 0-asteroids[i]){
                        flag = false;
                        break;
                    } else if(st[st.size()-1] < 0-asteroids[i]){
                        st.pop_back();
                    } else if(st[st.size()-1] == 0-asteroids[i]){
                        flag = false;
                        st.pop_back();
                        break;
                    }
                } else {
                    break;
                }
            }

            if(flag){
                st.push_back(asteroids[i]);
            }
        }

        
        return st;
    }
};


int main(){
    vector<int> nums = {5, 10, -5};
    vector<int> res = Solution().asteroidCollision(nums);
    for(int i = 0; i < res.size(); i++){
        cout << res[i]<< " ";
    }
    cout << endl;
    return 0;
}
