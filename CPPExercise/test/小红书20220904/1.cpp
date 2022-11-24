#include<iostream>
#include<vector>
using namespace std;

// ak

long long n, m, k;
int main(){
    cin >> n >> m >> k;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    
    long long i = 1;
    long long t = n;
    while(t < k){
        t = t * 2;
        i++;
    }
    //long long t1 = t / 2;
    long long isRev =(k - t/2)/n % 2; // 是否反序
    long long pos =(k - t/2)%n;
    if(isRev == 0){
        // 正序
        cout << nums[pos - 1] << endl;
    } else {
        cout << nums[n - pos] << endl;
    }
    return 0;
}
