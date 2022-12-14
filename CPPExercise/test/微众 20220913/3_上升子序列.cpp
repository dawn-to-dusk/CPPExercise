//
//  3_上升子序列.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/9/14.
//

/*
 小明刚刚学会用动态规划方法解决最长上升子序列(LIS)问题。LIS的O(n2)动态规划解法是这样的:设dp[1]为以1结尾的最长上升子序列的长度，首先令所有的dp[]=1，转移由 dp1]转移过来要求j€[1，1-7]且a<a。转移方程就是dp[1]=max(dpdp(]+1)。最后max dp[]就是答案。
 1≤j<i 1≤¡≤n
 明现在想知道:有多少个长度为n的整数序列，每个整数都在[1，m]之内，且这个序列的最长上升子序列的长度恰好等于3?由于答案可能会很大，求得的结果对998244353 取模即可。
 输入描述
 输入仅一行两个正整数n，m。3 ≤n≤500,1 ≤m≤10。
 输出描述
 输出一个整数，表示答案对 998244353取模后的结果。
 */
