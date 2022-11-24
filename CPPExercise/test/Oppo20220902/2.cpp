#include<iostream>
using namespace std;


int findStr(string str, string mod ) {
    // write code here
    for(int i = 0; i < str.length(); i++){
        bool flag = false;
        int k = i;
        int j =mod.length() - 1;
        for(; j >= 0; j--, k++){
            if(k >= str.length()){
                break;
            }
            if(str[k] == mod[j] || mod[j] == '*'){
                flag = true;
                continue;
            } else {
                flag = false;
                break;
            }
        }
        if(flag && j == -1){
            return k - 1;
        }
    }
    return -1;
}

int main(){
    char* str1 = "Hello world";
    char* str2 = "l*o";
    cout << findStr(str1, str2) << endl;
    return 0;
}
