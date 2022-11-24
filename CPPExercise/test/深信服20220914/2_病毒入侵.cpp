//
//  2_病毒入侵.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/9/15.
//

/*
 一年一度的入侵行动来了，病毒小绿被病毒大王安排去入侵多个主机。但是每个主机都装有了深信服强大的EDR杀毒设备。小绿想要避开这些杀毒设备去入侵主机，是一项非常困难的任务。
 好在，病毒大王赋予了小绿特殊的力量，让它能通过伪装去绕过杀毒设备的检测。
 小绿需要按顺序，去入侵n个主机，每个主机上的杀毒设备有自己的辨识度a[i]，如果小绿的伪装度v与杀毒设备的辨识度a[i]绝对值不超过x(主机的辨识精确度)，即|a[]-v|<=x，则病毒可以入侵成功当前主机。
 现给定n个主机的辨识度，问小绿最少需要变化多少次伪装度(伪装度可以取任意值)，才能按照顺序，成功入侵所有主机。注意，小绿初始时的伪装度可以取任意值，且不记人小绿变化的伪装次数。
 输入描述:
 给定正整数n和x，分别表示主机数和主机的辨识精确度。接下克
 分别表示这n个主机的辨识度。
 
 输出描述:
 输出一个整数，表示小绿最少需要变化多少次伪装度，才能入侵n个主机。
 
 5 4
 4 9 6 7 8
 
 0
 
 小绿将初始伪装度设置为6，由于1，9，6，7，8与6的绝对值都不超过4，因此小绿可以成功入侵这些主机。综上，小绿最少需要变化0次伪装度。
 【数据范围】
 1<=n<=100000，1<=a[i]，x<=100000000o
 */

// ak

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int N = 100010;
vector<int> nums;
int n, x;
int main(){
    cin >> n >> x;
    nums.resize(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    
    x = x * 2;
    int minN = nums[0];
    int maxN = nums[0];
    int cnt = 0;
    for(int i = 1; i < n; i++){
        minN = min(minN, nums[i]);
        maxN = max(maxN, nums[i]);
        
        if(maxN - minN > x){
            cnt++;
            maxN = nums[i];
            minN = nums[i];
        }
    }
    
    cout << cnt << endl;
    return 0;
}
