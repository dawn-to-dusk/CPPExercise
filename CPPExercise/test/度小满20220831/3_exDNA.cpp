//
//  3_exDNA.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/8/31.
//

/*
 科学家在外星球发现了一种全新的生物，该种生物的遗传物质与DNA类似，被称为exDNA
 与DNA类似，exDNA由9种碱基对依次连接而成，将这9种碱基对分别编号为1至9，则一段exDNA链可以写成一个字符串，例如:
 1376329476294518....
 进一步研究发现，如果exDNA中存在两个相邻的1号碱基对，则该段
 exDNA的表征将出现问题。因此科学家将exDNA分为两类:正常exDNA和错误 exDNA。正常exDNA中不含相邻的1号碱基对，错误exDNA包含至少一处相邻的1号碱基对。形式化地，设exDNA长度为n，第i个碱基对编号为ai，则当存在一个i使a;=a=1(1≤i≤n-1)时，该exDNA为错误exDNA，反之为正常exDNA。
 例如12445，2414183，1都是正常exDNA;11244，52112，67113都是错误exDNA。
 更进一步的研究发现，exDNA在复制时可能产生复制错误，表现为相邻的两个碱基对交换位置，例如12345复制后可能得到13245。由于发生错误的可能性很低，可以认为一段exDNA在复制时至多只会发生一次复制错误。在至多产生一次复制错误的条件下，如果一段exDNA复制后得到的一定是正常exDNA,则称其为安全exDNA;如果复制后可能得到错误exDNA，则称其为不安全 exDNA。
 例如12445，1，123123都是安全exDNA，2414183，1214，311都是不安全exDNA。
 请编写一个程序，计算有多少种不同的长度为n的安全exDNA链，结果对1000000007取模。
 输入描述
 输入一行，包含一个整数n，其中1≤n≤100000，表示exDNA链的长度。
 输出描述
 输出一行，包含一个整数，表示长度为n的安全exDNA链的种类数。答案对1000000007取模。
 
 input:
 3
 output:
 704
 提示
 长度为3的exDNA链有93=729种，其中111，1x1，x11，11x (2≤x≤9)共25种为不安全exDNA。
 */

#include<iostream>
using namespace std;
#define MOD 1000000007
#define N 100010

int dp[N][9]; // 第i位以j结尾的可能

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < 9; i++){
        dp[0][i] = 1;
        if(i == 0){
            dp[1][i] = 8;
        } else {
            dp[1][i] = 9;
        }
    }
    
    // 直接考虑安全数的情况
    for(int i = 2; i < n + 2; i++){
        for(int j = 0; j < 9; j++){
            if(j == 0){
                // 当前位为1，匹配上上一位不为1的所有情况，对于上上一位不为1的同时上一位可以为2-8的任意数
                for(int k = 1; k < 9; k++){
                    dp[i][j] = (dp[i][j] % MOD + dp[i - 2][k] % MOD * 8 % MOD) % MOD;
                }
            } else {
                // 当前位不为1，当前位可以匹配任意上一位情况
                for(int k = 0; k < 9; k++){
                    dp[i][j] = (dp[i][j] % MOD + dp[i - 1][k] % MOD) % MOD;
                }
            }
        }
    }
    
    // 最终结果是第n位为1-9的所有结果之和
    int res = 0;
    for(int i = 0; i < 9; i++){
        res = (res % MOD + dp[n - 1][i] % MOD) % MOD;
    }
    cout << res << endl;
    return 0;
}
