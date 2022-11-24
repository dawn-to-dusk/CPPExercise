//
//  t2.cpp
//  Test
//
//  Created by Baozhu Fang on 2022/9/3.
//
/*
 1
 3
 L 1
 L 1
 R 1
 
 1
 4
 R 1
 L 1
 L 1
 R 100
 */

#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        vector<char> action(n);
        vector<int> num(n);
        for(int j = 0; j < n; j++){
            cin >> action[j] >> num[j];
        }
        
        vector<int> res;
        for(int j = 0; j < n; j++){
            int pos = j;
            set<int> s;
            s.insert(pos);
            int step = 0;
            while(1){
                step++;
                if(action[pos] == 'L'){
                    pos = pos - num[pos];
                } else{
                    pos = pos + num[pos];
                }
                
                if(s.find(pos) != s.end()){
                    res.push_back(-1);
                    break;
                } else {
                    s.insert(pos);
                }
                
                if(pos < 0 || pos > n - 1){
                    res.push_back(step);
                    break;
                } else {
                    continue;
                }
            }
        }
        
        for(int j = 0; j < res.size() - 1; j++){
            cout << res[j] << " ";
        }
        cout << res[res.size()-1] << endl;
        res.clear();
        
    }
}
