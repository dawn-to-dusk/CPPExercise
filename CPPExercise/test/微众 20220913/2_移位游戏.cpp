//
//  2_移位游戏.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/9/14.
//

/*
 一天你正在玩一个游戏，游戏中给定一个数a，你需要通过一些简单的移位操作来将其变成b，在每次操作中，你可以将当前的数x变成以下六个数中的一个:
 x*2.x*4.x*8.x/2(如果x被2整除)，x/4(如果x被4整除)，x/8(如果x被8整除)
 例如，如果当前的数x=12，你可以将他变成24、48、96、6、3，你不能将其变成x/8，因为12不能被8整除。
 现在请问将给定的初始值a通过上述操作变成目标值b需要的最少的操作次数。
 输入描述
 第一行包含一个正整数t(1≤t≤100)，表示数据组数。
 接下来n行每行包括两个空格隔开的正整数a和b，分别表示初始值和目标值。

 输出描述
 输出n行，每行一个数表示通过上述操作将初始值a变成目标值b需要的最少的操作次数，如果最终无法得到b，则输出-1。
 */


/*
 4
 3 6
 16 2
 12 4
 1024 1
 
 1
 1
 -1
 4
 1 <= a, b <= 10^18
 */


#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std;


int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        long long a, b;
        cin >> a >> b;
        if(a == b){
            cout << 0 << endl;
            continue;
        }
        
        if(a < b){
            long long tmp = a;
            a = b;
            b = tmp;
        }
        if(a % b != 0){
            cout << -1 << endl;
            continue;
        }
        
        int cnt = 0;
        while(a > b){
            if(b * 8 <= a){
                b *= 8;
                cnt++;
                continue;
            } else if(b * 4 <= a){
                b *= 4;
                cnt++;
                continue;
            } else {
                b *= 2;
                cnt++;
                continue;
            }
        }
        
        if(a == b){
            cout << cnt <<endl;
        } else {
            cout << -1 << endl;
        }
    }
    
    return 0;
}
