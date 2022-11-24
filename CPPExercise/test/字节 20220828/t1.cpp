#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int getNum(int x){
    if((x&1) == 1){
        return 0;
    }
    return getNum(x>>1) + 1;
}


int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int m;
        cin >> m;
        vector<int> nums(m);
        for(int j = 0; j < m; j++){
            cin >> nums[j];
        }
        for(int j = 0; j < m; j++){
            if(nums[j] == 0){
                nums[j] = -1;
            } else {
                nums[j] = getNum(nums[j]);
            }
        }
        
        int maxL = 0, maxR = 0;
        int maxN = 0;
        int start = 0;
        int cur = 0;
    
        for(int i = 0; i < m; i++){
            if(nums[i] == -1){
                if(cur > maxN){
                    maxL = start;
                    maxR = i-1;
                    maxN = cur;
                }
                cur = 0;
                start=i+1;
            } else {
                cur+=nums[i];
            }
        }
        
        cout << maxL  + 1<< " " << maxR + 1 << endl;
    }
    
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 10;

typedef long long ll;

int n, k;
int a[N];
int f[N][30];
int Log[N];
ll sum[N];
inline void st()
{
    Log[0]=-1;
    for(register int i=1;i<=n;i++) Log[i]=Log[i>>1]+1;
    for(register int i=1;i<=n;i++) f[i][0]=a[i];
    for(register int j=1;j<=Log[n];j++)
        for(register int i=1;i+(1<<j)-1<=n;i++)
            f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
    return;
}

int get(int l, int r)
{
    //cout << l <<" " << r << '\n';
    k=Log[r-l+1];
    return min(f[l][k],f[r-(1<<k)+1][k]);
}


int main(){
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i ++)
    {
        scanf("%d", &a[i]);
        sum[i] = sum[i - 1] + a[i];
    }
    st();
    if(n == k)
    {
        cout << sum[n] << '\n';
        return 0;
    }
    else
    {
        ll ans = -2e18;
        for (int i = k; i <= n; i ++)
        {
            ans = max(ans, sum[i] - sum[i - k]);
        }
        for (int i = k + 1; i <= n; i ++)
        {
            ans = max(ans, sum[i] - sum[i - k - 1] -2 * get(i - k , i));
        }
        cout << ans << '\n';
    }
}ctrc + ctrv

