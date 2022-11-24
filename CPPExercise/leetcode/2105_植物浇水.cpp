//
//  2105_植物浇水.cpp
//  Tmp
//
//  Created by Baozhu Fang on 2022/8/13.
//

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int count = 0;
        int a = 0;
        int b = plants.size() - 1;
        int remainA = capacityA, remainB = capacityB;
        while(a < b) {
            if(remainA < plants[a]){
                remainA = capacityA;
                count++;
            }
            remainA -= plants[a++];
            
            if(remainB < plants[b]){
                remainB = capacityB;
                count++;
            }
            remainB -= plants[b--];
        }
        if(a == b) {
            int maxN = max(remainA, remainB);
            if(maxN < plants[a]) {
                count++;
            }
        }
        
        return count;
    }
};

int main(){
    int n, A, B;
    cin >> n >> A >> B;
    vector<int> plants(n);
    for(int i = 0; i < n; i++){
        cin >> plants[i];
    }
    Solution sol;
    cout << sol.minimumRefill(plants, A, B) << endl;
    return 0;
}
