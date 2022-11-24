//#include<iostream>
//#include<algorithm>
//#include<vector>
//#include<unordered_map>
//
//using namespace std;
//
//int main(){
//    int n;
//    cin >> n;
//    vector<int> nums(n);
//    unordered_map<int, int> um1;
//    unordered_map<int, int> um2;
//    for(int i = 0; i < n; i++){
//        cin >> nums[i];
//        if(i % 2 == 0){
//            um1[nums[i]]++;
//        } else {
//            um2[nums[i]]++;
//        }
//    }
//    int maxN[4][2];
//    for(auto [k, v] : um1){
//        if(v > maxN[0][1]){
//            maxN[1][0] = maxN[0][0];
//            maxN[1][1] = maxN[0][1];
//            maxN[0][0] = k;
//            maxN[0][1] = v;
//        } else if(v > maxN[1][1]){
//            maxN[1][0] = k;
//            maxN[1][1] = v;
//        }
//    }
//    for(auto [k, v] : um2){
//        if(v > maxN[0][1]){
//            maxN[1][0] = maxN[0][0];
//            maxN[1][1] = maxN[0][1];
//            maxN[0][0] = k;
//            maxN[1][1] = v;
//        } else if(v > maxN[1][1] && k != maxN[0][0]){
//            maxN[1][0] = k;
//            maxN[1][1] = v;
//        }
//    }
//    int a = maxN[0][0], b = maxN[1][0];
//    if(a == b){
//        cout << n / 2 << endl;
//        return 0;
//    }
//
//
//    int res1 = 0, res2 = 0;;
//    for(int i = 0; i < n; i++){
//        if(i % 2 == 0){
//            if(nums[i] != a){
//                res1++;
//            }
//            if(nums[i] != b){
//                res2++;
//            }
//        } else {
//            if(nums[i] != b){
//                res1++;
//            }
//            if(nums[i] != a){
//                res2++;
//            }
//        }
//    }
//
//    cout << min(res1, res2) << endl;
//}


#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<string.h>
using namespace std;

int n;
vector<long long> nums;
    
int getRes(int a, int b){
    if(a == b){
        return n + 1;
    }
    long long res1 = 0, res2 = 0;;
    for(int i = 0; i < n; i++){
        if(i % 2 == 0){
            if(nums[i] != a){
                res1++;
            }
            if(nums[i] != b){
                res2++;
            }
        } else {
            if(nums[i] != b){
                res1++;
            }
            if(nums[i] != a){
                res2++;
            }
        }
    }
    return min(res1, res2);
}

int main(){
    cin >> n;
    nums.resize(n);
    unordered_map<long long, int> um1;
    unordered_map<long long, int> um2;
    bool flag = true;
    int pre = -1;
    for(int i = 0; i < n; i++){
        cin >> nums[i];
        if(i % 2 == 0){
            um1[nums[i]]++;
        } else {
            um2[nums[i]]++;
        }
        if(nums[i] != pre){
            flag = false;
        }
        pre = nums[i];
    }
    if(flag){
        cout << n / 2 << endl;
        return 0;
    }
    
    int maxCnt1 = 0;// 最大
    int maxCnt2 = 0;// 第二
    vector<int> max1;
    vector<int> max2;
    for(auto [k, v] : um1){
        if(v > maxCnt1){
            maxCnt2 = maxCnt1;
            max2 = max1;
            max1.clear();
            max1.emplace_back(k);
        } else if(v > maxCnt2){
            maxCnt2 = v;
            max2.clear();
            max2.emplace_back(k);
        }
    }
    
    int maxCnt3 = 0;// 最大
    int maxCnt4 = 0;// 第二
    vector<int> max3;
    vector<int> max4;
    for(auto [k, v] : um2){
        if(v > maxCnt3){
            maxCnt4 = maxCnt3;
            max4 = max3;
            max3.clear();
            max3.emplace_back(k);
        } else if(v > maxCnt4){
            maxCnt4 = v;
            max4.clear();
            max4.emplace_back(k);
        }
    }
    
    
    int a, b;
    int res = n+1;
    for(int i = 0; i < max1.size(); i++){
        for(int j = 0; j < max3.size(); j++){
            if(max1[i] == max3[j]){
                continue;
            } else {
                res = getRes(max1[i], max3[j]);
            }
        }
    }
    if(res == n+1){
        int res1 = n+1;
        for(int i = 0; i < max2.size(); i++){
            for(int j = 0; j < max3.size(); j++){
                if(max2[i] == max3[j]){
                    continue;
                } else {
                    res1 = getRes(max2[i], max3[j]);
                }
            }
        }
        int res2 = n+1;
        for(int i = 0; i < max1.size(); i++){
            for(int j = 0; j < max4.size(); j++){
                if(max1[i] == max4[j]){
                    continue;
                } else {
                    res2 = getRes(max1[i], max4[j]);
                }
            }
        }
        res = min(res1, res2);
    }
    
    if(res == n+1){
        for(int i = 0; i < max2.size(); i++){
            for(int j = 0; j < max4.size(); j++){
                if(max2[i] == max4[j]){
                    continue;
                } else {
                    res = getRes(max2[i], max4[j]);
                }
            }
        }
    }
    
    
    cout << res << endl;
    return 0;
}

