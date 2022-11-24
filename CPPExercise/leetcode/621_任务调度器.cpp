//
//  621_任务调度器.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/8/21.
//

/**
 假设执行次数最多的任务执行了maxN次，其中有maxCount个任务执行了maxN次，
 如果剩余任务都可以在待命时间完成，那么最少需要(maxN-1) * (n+1） + maxN时间
 如果剩余任务不能都在待命时间完成，那么一定能够做到不需要空余待命时间，最少需要的时间次数就是总任务数
 */

#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int tCount = tasks.size();
        unordered_map<char, int> tMap;
        int maxN = 0;
        for(auto t : tasks){
            if(tMap.find(t) == tMap.end()){
                tMap[t] = 1;
            } else {
                tMap[t]++;
            }
            maxN = max(tMap[t], maxN);
        }
        int maxCount = 0;
        for(auto [t, c]:tMap){
            if(c == maxN){
                maxCount++;
            }
        }
        int time = (maxN - 1) * (n + 1) + maxCount;
        return max(tCount, time);
    }
};
