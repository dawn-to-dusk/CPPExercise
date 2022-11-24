//
//  位运算-二进制中1的个数acwing801.cpp
//  CPPExercise
//
//  常用操作：
//  - 求第k位数： n >> k & 1
//  - 返回最后一位1： lowbit(n) = n & -n
//     n&-n = n&(~n+1) => n取反后最后一位1后都是0，再加一，那么最后一位1后面都变成1（与原来相同），最后一位1会被进位变成1，与本身的1相与，还是1，最后一位1前面还是取反状态（与原来都不同），相与后全部为0
//
//  Created by Baozhu Fang on 2022/7/29.
//

#include<iostream>
#include<vector>
using namespace std;

// 位运算做法：lowbit
int lowbit(int x){
    return x & -x;
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        int count = 0;
        while(x){
            x -= lowbit(x);
            count++;
        }
        cout << count <<endl;
    }
}

//// 暴力做法：取余
//int main(){
//    int n;
//    cin >> n;
//    for(int i = 0; i < n; i++){
//        int num;
//        cin >> num;
//
//        int count = 0;
//        while(num > 0){
//            if(num%2 != 0){
//                count++;
//            }
//            num /= 2;
//        }
//        cout << count << " ";
//    }
//
//    cout << endl;
//    return 0;
//}
