//
//  2.cpp
//  Test
//
//  Created by Baozhu Fang on 2022/9/4.
//

#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
#include<string.h>
using namespace std;
#define MAXN 1e9 + 10

/*
 5
 -6 0 2 -2 3
 */

//long long abs(long long x){
//    if(x < 0){
//        return 0 - x;
//    } else {
//        return x;
//    }
//}
// 73

int flag[30001];
int main(){
    int n;
    cin >> n;
    vector<long long> nums(n);
    int pos7 = 0;
    long long min7 = MAXN;
    vector<long long> up1(n);
    vector<long long> down1(n);
    for(int i = 0;i < n; i++){
        cin >> nums[i];
        
        if(abs(abs(nums[i]) - 7) < abs(abs(min7) - 7)){
            pos7 = i;
            min7 =nums[i];
        } else if(abs(abs(nums[i]) - 7) == abs(abs(min7) - 7)){
            if(abs(abs(nums[i]) - 1) > abs(abs(min7) - 1)){
                pos7 = i;
                min7 =nums[i];
            }
        }
        
        up1[i] = abs(nums[i] - 1);
        down1[i] = abs(nums[i] + 1);
    }
    
    if(n == 1){
        cout << abs(nums[0] - 7) << endl;
        return 0;
    }
    
    //up1.erase(up1.begin() + pos7);
    //down1.erase(up1.begin() +pos7);
    
//    sort(up1.begin(), up1.end());
//    sort(down1.begin(), down1.end());
    
    //vector<int> flag(n);
    memset(flag, 0, sizeof(flag));
    flag[pos7] = 7;
    
    long long res = abs(abs(min7) - 7);
    int cnt = n - 1;
    if(min7 < 0){
        long long min1 = MAXN;
        int pos1 = -1;
        for(int i = 0; i < n; i++){
            if(flag[i] != 0){
                continue;
            }
            if(down1[i] < min1){
                min1 = down1[i];
                pos1 = i;
            } else if(down1[i] == min1 && up1[i] > up1[pos1]){
                min1 = down1[i];
                pos1 = i;
            }
        }
        res += down1[pos1];
        cnt--;
        flag[pos1] = -1;
    }
    
    bool tmp = true;
    for(int i = 0; i < n; i++){
        if(flag[i] != 0){
            continue;
        }
        if(up1[i] <= down1[i]){
            res += up1[i];
            flag[i] = 1;
        } else {
            res += down1[i];
            flag[i] = -1;
            if(tmp){
                tmp = false;
            } else {
                tmp = true;
            }
        }
    }
    
    if(!tmp){
        int x = MAXN;
        for(int i = 0; i < n; i++){
            if(flag[i] == 1){
                if(down1[i] - up1[i] < x){
                    x =down1[i] - up1[i];
                }
            } else if(flag[i] == -1){
                if(up1[i] - down1[i] < x){
                    x = up1[i] - down1[i];
                }
            }
        }
        res += x;
    }
    
    cout << res << endl;
    return 0;
}
