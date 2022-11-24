//
//  tmp2.cpp
//  Test
//
//  Created by Baozhu Fang on 2022/10/9.
//

/*
 1
 4 4
 3 0 5 6
 0 9 -1 4
 -1 8 1 1
 4 -1 5 -1
 
 12
 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int matrix[510][510];
int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n, m;
        cin >> n >> m;
        //matrix.resize(n);
        for(int i = 0; i < n; i++){
            //matrix[i].resize(m);
            for(int j = 0; j < m; j++){
                cin >> matrix[i][j];
            }
        }
        
        int maxN = max(n, m) - 1;
        int res = 0;
        for(int k = 0; k < maxN; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    if(i+k>n-1) break;
                    if(j+k>m-1) break;
                    int cur = 0;
                    bool flag = false;
                    for(int a = i; a <= i+k; a++){
                        for(int b = j; b <= j+k; b++){
                            if(matrix[a][b] == -1){
                                cur = 0;
                                flag = true;
                                break;
                            } else {
                                cur += matrix[a][b];
                            }
                        }
                        if(flag) break;
                    }
                    res = max(res, cur);
                }
            }
        }
        
        cout << res << endl;
    }
    return 0;
    
}

