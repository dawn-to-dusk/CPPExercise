#include<iostream>
#include<string.h>
#include<unordered_map>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 返回满足题意的最小操作数
     * @param str string字符串 给定字符串
     * @return int整型
     */
    int minOperations(string str) {
        // write code here
        unordered_map<char, int> um;
        for(int i = 0; i < str.length(); i++){
            um[str[i]]++;
        }
        
        int pos = 0;
        int res = 0;
        for(auto [k, v] : um){
            while(v > 1){
                v -= 2;
                um[k] = v;
                
                bool first = true;//
                bool flag = false;
                for(int i = pos; i!=pos && !first ; i= (i+1)%26){
                    if(um.find('a' + pos) == um.end() || um['a'+pos] < 1){
                        um['a' + pos]++;
                        pos++;
                        flag = true;
                        break;
                    }
                    first = false;
                }
                
                if(!flag){
                    int minN = 1000;
                    int minPos = 0;
                    for(int j = 0; j < 26; j++){
                        if(um['a' + j] < minN){
                            minN = um['a' + j];
                            minPos = j;
                        }
                    }
                    um['a' + minPos]++;
                }
                res++;
            }
        }
        return res;
    }
};

int main(){
    string str = "";
    for(int i = 0; i < 1000; i++){
        str = str + 'a';
    }
    //cin >> str;
    cout << Solution().minOperations(str) << endl;
    return 0;
}

