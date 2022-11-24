
#include<iostream>
#include<vector>
using namespace std;
//#define MOD 1000000007
const long long MOD = 1e9 + 7;
const long long MAXN = 1e6 + 10;

long long nums[MAXN];
long long A[MAXN], B[MAXN];

long long mypow(long long n, long long k){
    long long res = 1;
    n = n % MOD;
    while(k > 0){
        res = res % MOD * n % MOD;
        n = n % MOD * n % MOD;
        k = k >> 1;
    }
    return res;
}

void set(){
    A[0] = 1;
    B[0] = 1;
    for(int i = 1; i < MAXN; i++){
        A[i] = A[i-1]  * i % MOD;
        B[i] = mypow(A[i], MOD-2);
    }
}

long long getNum(long long n, long long i){
    if(n < i || i < 0){
        return 0;
    } else {
        return A[n] % MOD * B[i] % MOD * B[n - i] % MOD;
    }
//    vector<long long> pre = getNums(n - 1);
//    vector<long long> nums(n);
//    nums[0] = 1;
//    nums[n - 1] = 1;
//    for(int i = 1; i < n - 1; i++){
//        nums[i] = pre[i - 1] + pre[i];
//    }
//    return nums;
}



int main(){
    long long n;
    cin >> n;
    if(n == 1 || n == 2){
        cout << 1 << endl;
        return 0;
    }
    //vector<long long> nums = getNums(n);
    long long res = 1;
    for(int i = 0; i < n; i++){
        res = res % MOD * getNum(n-1, i) % MOD;
    }
    cout << res << endl;
    return 0;
}



