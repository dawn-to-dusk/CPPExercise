//#include<iostream>
//#include<string.h>
//using namespace std;
//
//long long res;
//long long flag[1000000000];
//
//long long fun(long long n){
//    if(flag[n] == 0){
//        if(n == 1){
//          flag[n] = 1;
//        } else if(n == 2){
//            flag[n] = 2;
//        } else {
//            flag[n] = fun(n/2)+1;
//        }
//
//        res += flag[n];
//    }
//
//    return flag[n];
//}
//
//int main(){
//    long long n;
//    cin >> n;
//    memset(flag, 0, sizeof(flag));
//    fun(n);
//    cout << res << endl;
//    return 0;
//}


#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int> parents;
vector<int> value;

bool check(vector<int> v){
    for(int i = 0;i < n; i++){
        if(v[i] != 0){
            return false;
        }
    }
    return true;
}

void add(int n){
    value[n]++;
    add(parents[n]);
    
}

void sub(int n){
    
}


int main(){

    cin >> n;
    parents.resize(n);
    value.resize(n);
    parents[0] = 1;
    for(int i = 1; i < n; i++){
        cin >> parents[i];
    }
    for(int i = 0; i < n; i++){
        cin >> value[i];
    }
    
    int res = 0;
    sort(parents.begin(), parents.end());
    for(int i = n -1;i > 0; i--){
        
    }
    
}

