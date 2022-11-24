
/*
 英文浏览器直接翻译：
 一条线上有N个点，编号从0到N-1，其坐标在数组A中给出。对于每个1(0≤l<N)，线上点号|的坐标为Al.点的坐标不必是不同的。
 对于给定的整数M，如果子集中任意两个点之间的距离可被M整除，则称这些点的子集是M对齐的。
 您的任务是找到给定的最大M对齐子集的大小N个点的集合。
 
 例如，考虑整数M=3和数组A使得:
 A[0]=-3A[1]=-2A[2]=1A[3]=0A[4]=8A[5]=7A[6]=1
 包含编号为 1、2、5 和6的点(坐标分别为 -2、1、7和 1)的子集是3 对齐子集的示例，因为:
 - 编号为1和2的点之间的距离为abs (A[1]-A[2])=3
 - 从点号5到点号1和2的距离分别为9和6
 - 从点号6到点号 1、2 和5的距离分别为 3、0和6
 并且这些距离都可以被 M=3整除。这个子集的大小是4，并且没有更大的 3- aligned 子集。
 
 写一个函数:
 整数解(向量<int>&A,intM);
 
 即，给定一个由N个整数和一个整数 M 组成的数组 A，返回最大的 M 对齐子集的大小。
 例如，给定M=3和A=-3-210871]，该函数应返回 4，如上所述。
 给定M=8和A=[711184,10]，函数应该返回1，因为可以创建一个仅包含一个(任意)点的子集。
 请注意，这是最大的8对齐子集，因为任何给定的点对的距离都不能被8整除。
 为以下假设编写一个有效的算法:
 - N是[0..100,000]范围内的整数;
 - M 是[1.. 100,000]范围内的整数;
 - 数组A的每个元素都是[-1,000,000,000.1,000,000,000]范围内的整数。
 */


/*
 7 3
 -3 -2 1 0 8 7 1
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int lowbit(int x){
    return x & -x;
}

int getCnt(int x){
    int count = 0;
    while(x){
        x -= lowbit(x);
        count++;
    }
    return count;
}


int solution(vector<int> &A, int M) {
    // write your code in C++ (C++14 (g++ 6.2.0))
    
    int maxN = 0;
    //int res = 0;
    int n = A.size();
    int states = 1 << n;
    // i是一种取元素策略
    for(int i = 1; i < states; i++){
        bool flag = true;
        if(getCnt(i) == 1){
            continue;
        }
        int pre = -1;
        for(int j = 0; j < n; j++){
            // 第j位为1
            if(i >> j & 1){
                if(pre == -1){
                    pre = A[j];
                } else {
                    if((A[j] - pre)%M != 0){
                        flag = false;
                        break;
                    }
                }
            }
        }
        if(flag) {
            maxN = max(maxN, getCnt(i));
        }
    }
    
    return maxN == 0 ? 1 : maxN;
}


int main(){
    int N, M;
    cin >> N >> M;
    vector<int> nums(N);
    for(int i = 0; i < N; i++){
        cin >> nums[i];
    }
    
    cout << solution(nums, M) << endl;
    return 0;
    
}

