//
//  t4.cpp
//  Test
//
//  Created by Baozhu Fang on 2022/9/3.
//

#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<iomanip>
using namespace std;

//int nums[1010];
vector<int> nums;
vector<vector<int>> segment;
int n, c, r, m;
double res;
int cnt;

int me, mt;
/*
 4 2 1
 1 650
 2 640
 3 630
 4 620
 
 3 2 2
 1 650
 2 640
 3 600
 
 3 1 2
 1 650
 2 640
 3 600
 
 3 3 2
 1 650
 2 640
 3 600

 
 */


void getSum(int t, int sum, int nn){
    if(t >= c){
        double cur = double(sum) / double(nn);
        res += cur;
        cnt++;
        return;
    }
    if(t == mt){
        getSum(t+1, sum + me, nn + 1);
        return;
    }
    
    int stateMax = 1 << (m-1);
    for(int i = 1, j = 0; i <= stateMax; i = i << 1, j++){
        if(j < segment[t].size()){
            getSum(t+1, sum + segment[t][j], nn + 1);
        } else {
            getSum(t+1, sum, nn);
        }
    }
}

int main(){
    cin >> n >> c >> r;
    m = ceil(double(n) / double(c)); // 教室个数
    
    segment.resize(c + 1); // 一共c段，每个段m个人
    for(int i = 0; i < n; i++){
        int x, tmp;
        cin >> x;
        cin >> tmp;
        nums.push_back(tmp);
    }
    sort(nums.begin(), nums.end());
    reverse(nums.begin(), nums.end());
    
    for(int i = 0;i < n; i++){
        int t = ceil(double(i + 1) / double(m)) - 1; // 所在段
        segment[t].push_back(nums[i]);
    }
    
    me = nums[r-1];
    mt = ceil(double(r) / double(m)) - 1; // 我所在的段
    
    getSum(0, 0, 0);
    
    cout << fixed << showpoint <<  setprecision(2) << res / double(cnt) << endl;
    return 0;
}
