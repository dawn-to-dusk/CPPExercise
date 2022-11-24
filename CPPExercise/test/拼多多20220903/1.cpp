#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;


int n, k;

string s[1010];

void op(string &str, int i){
    char oc = str[i];
    char nc = str[i]- 1;
    for(int j = 0; j < n; j++){
        if(str[j] == oc){
            str[j] = nc;
        }
    }
    //replace(str.begin(), str.end(), str[i], tmp);
}

string getStr(int k, string str){
    if(k <= 0){
        return str;
    }
    
    int i = 0;
    while(i < n && str[i] == 'a'){
        i++;
    }
    for(int j = 0; j < n; j++){
        if(i < n && (str[i] - 'a') < k){
            i++;
        }
    }
    
    op(str, i);
    return getStr(--k, str);
}

int main(){
    int t;
    cin >> t;
    for(int i = 0;i < t; i++){
        string str;
        cin >> n >> k >> str;
        cout << getStr(k, str) << endl;;
        //cout << getStr(k, str) << endl;;
    }
    return 0;
}
