//
//  扑克牌魔术.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/8/26.
//
/*
 小猿会表演扑克牌魔术：已知一副牌的初始顺序，经过多轮洗牌，仍然能看破任意一张牌的牌面。对于N张的一副牌，小猿的一次洗牌操作如下：将牌分为两叠，分别为前 N/2 张和后 N - N/2 张；接下来使两叠纸牌一张叉一张地交错叠在一起，原先第一张的纸牌洗牌后处于第二张。
 你能破解小猿魔术的秘密吗？

 输入描述:
 第一行输入两个正整数 N M，2 <= N <= 100, 1 <= M <= 200
 第二行输入N个正整数，表示初始牌序列

 输出描述:
 输出经过M次洗牌后的序列
 
 输入例子1:
 6 2
 3 1 4 2 5 6

 输出例子1:
 1 2 6 3 4 5

 例子说明1:
 3 1 4 2 5 6 -> 2 3 5 1 6 4 -> 1 2 6 3 4 5
 */

#include<iostream>
#include<vector>
using namespace std;


int  N, M;
vector<int> nums;
vector<int> nums1;

int main(){
    cin >> N >> M;
    nums.resize(N);
    nums1.resize(N);
    for(int i = 0; i < N; i++){
        int v;
        cin >> nums[i];
    }
    
    for(int j = 0; j < M; j++){
        int x = 1;
        for(int i = 0; i < N / 2; i++){
            if(i < N / 2){
                nums1[i + x] = nums[i];
                x++;
            }
        }
        int i = N - 1;
        if(N % 2 != 0){
            nums1[N - 1] = nums[N - 1];
            i--;
        }
        x = 1;
        for(; i >= N / 2; i--){
            nums1[i - x] = nums[i];
            x++;
        }
        nums = nums1;
    }
    
    
    for(int i = 0; i < N; i++){
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
    
}

