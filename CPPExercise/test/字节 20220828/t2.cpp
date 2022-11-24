//
//  t2.cpp
//  Test
//
//  Created by Baozhu Fang on 2022/8/28.
//

//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;


//const int N = 2e6 + 10;
//vector<int> M[N];
//int res[N];
//int cnt[N];
//
//class Solution{
//public:
//    int n;
//
//    void str2nums(string str, vector<int> &nums){
//        int pos1 = 0;
//        int pos2 = str.find(' ');
//        while(string::npos != pos2){
//            nums.emplace_back(stoi(str.substr(pos1, pos2 - pos1)));
//            pos1 = pos2 + 1;
//            pos2 = str.find(' ', pos1);
//        }
//        if(pos1 != str.length()){
//            nums.emplace_back(stoi(str.substr(pos1)));
//        }
//    }
//
//    void solve(){
//        scanf("%d", &n);
//        getchar();
//
//        string s;
//        getline(cin, s);
//        vector<int> feature;
//        str2nums(s, feature);
//
//        // 每一行处理
//        for(int i = 1; i < n; i++){
//            getline(cin, s);
//            vector<int> cur;
//            str2nums(s, cur);
//            int x = cur[0];
//            for(int j = 1; j < cur.size(); j++){
//                M[x].emplace_back(cur[j]);
//                cnt[cur[j]]++;
//            }
//        }
//
//        vector<int> ans;
//        for(int i = 1; i < n; i++){
//            if(cnt[i] == 0){
//                ans.emplace_back(i);
//            }
//        }
//        for(int i = 0; i < ans.size(); i++){
//            res[ans[i]] = 1;
//            for(auto j : M[ans[i]]){
//                cnt[j]--;
//                if(cnt[j] == 0){
//                    ans.emplace_back(j);
//                }
//            }
//        }
//
//        for(int i = 0; i < feature.size(); i++){
//            cout << res[feature[i]] << " " ;
//        }
//        cout << endl;
//
//    }
//
//
//};
//
//int main(){
//    Solution().solve();
//
//    return 0;
//}



#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


const int N = 2e6 + 10;


int n;
int k;
vector<int> nums;
vector<int> sum;
int main(){
    cin >> n >> k;
    nums.resize(n+1);
    sum.resize(n+1);
    for(int i = 1; i <= n; i++){
        cin >> nums[i];
        sum[i] = sum[i-1] + nums[i];
    }
    
    vector<int> state;
    state.resize(n+1);
    flag[0] = -1;
    for(int i = 1; i <= n; i++){
        
    }
}





