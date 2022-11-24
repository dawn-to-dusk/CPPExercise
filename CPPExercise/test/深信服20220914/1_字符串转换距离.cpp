//
//  1_字符串转换距离.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/9/14.
//

#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

/*
 horse
 rose
 2
 */

// ak

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * @param a string字符串 字符串1
     * @param b string字符串 字符串2
     * @return int整型
     */
    
    int minDistance(string a, string b) {
        int dp[10000][10000];
        // write code here
        if(a== ""){
            return b.length();
        }
        if(b == ""){
            return a.length();
        }
        
        for(int i = 0; i <= a.length(); i++){
            dp[i][0] = i;
        }
        for(int i = 1; i <= b.length(); i++){
            dp[0][i] = i;
        }
        
        for(int i = 1; i <= a.length(); i++){
            for(int j = 1; j <= b.length(); j++){
                dp[i][j] = min(dp[i-1][j] + 1, min(dp[i][j-1] + 1, dp[i-1][j-1] + (a[i-1] == b[j-1] ? 0 : 1)));
            }
        }
        
        
        return dp[a.length()][b.length()];
        
    }
};

int main(){
    string a, b;
    cin >> a >> b;
    cout << Solution().minDistance(a, b) << endl;
    return 0;
}
