//
//  z1.cpp
//  Test
//
//  Created by Baozhu Fang on 2022/9/16.
//

/*
  有四个同学按1-N号的顺序围成一个圈，己知第i位周学想得到Ai块糖，从1号同学开始按1-N德环的顺序(即按1，2，…，N，1，2，…，N，1，…的顺序循环)依次给每位同学发一块糖，如果第i位同学拿到了至少Ai块糖就会回家，继续发糖时则会跳过已经回家的同学。问哪位同学得到了第K块糖?
  输入描述:
  第一行两个正整数N，K;
  第二行N个正整数，第i个数表示Ai。
  输出描述:
  输出一个正整数i，表示编号为i的同学得到了第k块糖。
  
 */

/*
 5 10
 2 1 5 2 4
 3
 发糖顺序为1，2，3，4，5，1，3，4，5，3，5，3，5，3，所以第10块糖发给3号同学。
 
 6 3333333333
 1 1000000000 1000000000 1 1000000000 1000000000
 5
 发糖顺序为1，2，3，4，5，6，2，3，5，6，2，3，5，6,... 形成循环。因为3333333333 - 6除以4的余数为3，可以推出第3333333333块糖发给[2，3，5，6]循环节中的第3位，即5号同学。
 
 
 对于前20%的数据，N<=10;
 对于前40%的数据，Ai<=1000;
 对于前60%的数据，N<=1000;
 对于100%的数据，N<=1e5，Aj<=1e9，k不会超过所有Ai之和。注意k的取值可能超过231，需要使用64位整型存储。
 */

// ak
#include<iostream>
#include<vector>
using namespace std;

const int N = 100010;
long long nums[N];
long long tmp[N];
long long n, k;

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> nums[i];
        tmp[i] = nums[i];
    }
    sort(tmp, tmp + n);
    
    int i = 0;
    while(k - (tmp[i]-tmp[i-1]) * n > 0){
        k = k - (tmp[i]-tmp[i-1]) * n;
        i++;
        n--;
        while(tmp[i] == tmp[i-1]){
            i++;
            n--;
        }
    }
    if(k - (tmp[i]-tmp[i-1]) * n == 0){
        cout << n << endl;
        return 0;
    }
    
    
    while(k - n > 0){
        k -= n;
    }
    
    int pos = 0;
    for(int kk = 0; kk < k; pos++){
        if(nums[pos] > tmp[i-1]){
            kk++;
        }
    }
    cout << pos << endl;
    return 0;
    
}

