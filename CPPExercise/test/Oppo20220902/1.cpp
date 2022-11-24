//
//  wakelock.cpp
//  Test
//
//  Created by Baozhu Fang on 2022/9/2.
//

#include<iostream>
#include<vector>
#include<map>
using namespace std;


class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 输入参数是每个应用持有WakeLock的起始时间及结束时间，函数返回值是每个应用对总WakeLock时长的贡献值，返回值vector里面的每个元素的数值累加即为手机总的持有WakeLock的时长。
     * @param wakeLock int整型vector<vector<>> vector<vector<int>>的每个元素代表某个应用的持有WakeLock的信息，内部的vector<int>，元素按照奇偶排列，偶数元素代表拿WakeLock的起始时间点，奇数代表释放WakeLock的时间点
     * @return int整型vector
     */
    
//    int getSum(vector<int> nums){
//        int up = 0;
//        int down = 1;
//        for(int i = 0; i < nums.size(); i++){
//            up += nums[i];
//            down *= nums[i];
//        }
//        return up/down;
//    }
    vector<int> getWakeLockContrib1(vector<vector<int> >& wakeLock) {
        // write code here
        map<int, vector<int>> startM;
        for(int i = 0; i < wakeLock.size(); i++){
            for(int j = 0; j < wakeLock[i].size(); j++){
                int start, end;
                if(j % 2 == 0){
                    start = wakeLock[i][j];
                    end = wakeLock[i][j+1];
                    for(int k = start; k < end; k++){
                        startM[k].push_back(i);
                    }
                }
                
            }
        }
        
        vector<double> res(wakeLock.size());
        //vector<vector<int>> add(wakeLock.size());
        for(auto [k,v]:startM){
            int n = v.size();
            for(int i = 0; i < n; i++){
                res[v[i]] += 1.0/double(n);
                //add[v[i]].push_back(n);
            }
        }
        
        vector<int> res1(wakeLock.size());
        for(int i = 0; i < res.size(); i++){
            //res[i] += getSum(add[i]);
            res1[i] = int(res[i]);
        }
        return res1;
    }
    
    
    vector<int> getWakeLockContrib(vector<vector<int> >& wakeLock) {
            // write code here
            map<int, vector<int>> startM;
            int minT = wakeLock[0][0];
            int maxT = wakeLock[0][0];
            for(int i = 0; i < wakeLock.size(); i++){
                for(int j = 0; j < wakeLock[i].size(); j++){
                    int start, end;
                    if(j % 2 == 0){
                        start = wakeLock[i][j];
                        minT = min(minT, start);
                        end = wakeLock[i][j+1];
                        maxT = max(maxT, end);
                    }
                    
                }
            }
            vector<vector<int>> time(wakeLock.size(), vector<int> (maxT - minT + 1));
            for(int i = 0; i < wakeLock.size(); i++){
                for(int j = 0; j < wakeLock[i].size(); j++){
                    int start, end;
                    if(j % 2 == 0){
                        start = wakeLock[i][j];
                        end = wakeLock[i][j+1];
                        for(int k = start; k < end; k++){
                            time[i][k-minT] = 1;
                        }
                    }
                    
                }
            }
            
            vector<int> res(wakeLock.size());
        vector<int> ts(maxT - minT + 1);
        for(int i = 0; i < maxT - minT + 1; i++){
            int sum = 0;
            for(int j = 0; j < wakeLock.size(); j++){
                if(time[j][i] == 1){
                    sum++;
                }
            }
            ts[i] = sum;
        }
            for(int i = 0; i < wakeLock.size(); i++){
                double len = 0;
                for(int j = 0; j < time.size(); j++){
                    if(time[i][j] == 1){
                        len = len + 1;
                    } else {
                        res[i] += int(len/double(sum[j]));
                        len = 0;
                    }
                }
            }
            

            return res;
        
        }

};



int main(){
    vector<vector<int>> wakeLock = {
        {1234, 1240},
//        {1236, 1239},
//        {1236, 1239},
        {1236, 1238, 1245, 1250},
    };
    vector<int> res = Solution().getWakeLockContrib(wakeLock);
    for(int i = 0; i < res.size(); i++){
        cout <<  res[i] << endl;
    }
    return 0;
}

