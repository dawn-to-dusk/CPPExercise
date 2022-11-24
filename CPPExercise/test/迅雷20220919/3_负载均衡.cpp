//
//  xl3.cpp
//  Test
//
//  Created by Baozhu Fang on 2022/9/19.
//

/*
 移动使得每个worker的任务数量一样，求最少移动几次
 9 8 17  6
 3
 */

// ak

#include<iostream>
#include<vector>
using namespace std;


int main(){
    vector<int> nums;
    int tmp;
    int sum = 0;
    while(cin >> tmp){
        nums.emplace_back(tmp);
        sum += tmp;
    }
    
    int n = nums.size();
    int avg = sum / n;
    int cnt = 0;
//    int bOut = 0;
//    int bIn = 0;
    int pre = 0;
    int start = 0;
    for(int i = 0; i < n; i++){
        pre += nums[i];
        if(pre % avg == 0 && pre/avg == i-start+1){
            pre = 0;
            start = i+1;
        } else{
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
    
}

