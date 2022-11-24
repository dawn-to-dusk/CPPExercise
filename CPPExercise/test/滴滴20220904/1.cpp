/*
 5 2
 3 10 5 4 2
 
 4
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int MAXN = 100000 + 10;

int n, k;
//long long nums[MAXN];
vector<long long> nums;
//long long leftSum;
//long long leftSum;
//long long sum[MAXN][MAXN];

long long solve(long long l, long long r, long long preN, long long left, long long right){
    if(l >= r){
        return l;
    }
    //int len = r - l + 1;
    long long mid = (l + r + 1) >> 1;
    long long sum = 0;
    //long long nCur = 0;
    
    if(left == 0){
        //nCur = preN - mid;
        for(long long i = mid; i < r; i++){
            sum += nums[i];
        }
        sum = right - sum;;
        //nCur = mid;
    } else {
        //mid = preN + mid;
        for(long long i = l; i < mid; i++){
            sum += nums[i];
        }
        sum = left + sum;
        //nCur = mid;
    }
    
    if((sum/mid) * k >= nums[mid - 1]){
        return solve(mid, r, mid, sum, 0);
    } else {
        if(l + 1 == r){
            return l;
        }
        return solve(l, mid, mid, 0, sum);
    }
}

int main(){
    cin >> n >> k;
    nums.resize(n);
    for(int i = 0;i < n; i++){
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    long long mid = (n - 0 + 1) / 2;
    long long sum = 0;
    for(int i = 0; i < mid; i++){
        sum += nums[i];
    }
    
    long long res;
    if((sum/mid) * k >= nums[mid - 1]){
        res = solve(mid, n, mid, sum, 0);
    } else {
        res = solve(0, mid, mid, 0, sum);
    }
    
    cout << res << endl;
    return 0;
}

