//
//  2_消除方块.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/9/5.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;
// 样例

/*
 现在要求你写一个算法法，计算出未被清除的方块救目。
 产生满除的条件!假设A、日个方块的坐标分别为(a,a2)和(b,b2)，如果 a7>b1Ha2--b2，则A被消除。
 例如:A(2.5)和日(2,8)，因为A的左侧的坐标和B的左侧的坐标一样，而A的右侧的坐标小于目的右侧坐标，所以A被消除。
 下国中，第三个(最下面)方块被第一个(最上面)方块消除，剩下两个方块。
 说明:消除与方块的上下顺序无关。
 输入描述:
 输入首行为方块个数，然后输入着千个方块的左右坐标，左右坐标用空格分割，每个方块单独一行，如
 3
 1 8
 3 10
 2 4
 表示三个左右坐标分别为(1,8)、(3,10)和(2,4)的方块。
 输出描述:
 输出消去被覆盖方块后剩下的方块数，如上面三个方块，第三个方块被消去后，剩下2个方块，因此返回2.
 
 input:
 3
 1 8
 3 10
 2 4
 output:
 2
 
 input:
 3
 1 4
 3 6
 2 8
 output:
 2
 
 ak
 */
int main() {
    // 根据输入描述获取入参
    int n;
    cin >> n;
    map<int, int> mm;
    for(int i = 0; i < n; i++){
        int k, v;
        cin >> k >> v;
        if(mm.find(k) != mm.end()){
            if(v > mm[k]){
                mm[k] = v;
            }
        } else {
            mm[k] = v;
        }
    }
    
    int preK = 0, preV = 0;
    int cnt = 0;
    for(auto [k,v] : mm){
        if(preK == preV && preK == 0){
            preK = k;
            preV = v;
            cnt++;
            continue;
        }
        
        if(v <= preV){
            continue;
        } else {
            preV = v;
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
        
