/**
 输入第一行为用例数M
 其后输入每两行一个用例：
 第一行一个整数N，后面N个单词，空格隔开，单词可能重复
 第二行一个整数K，后面K个停用词，停用词不统计，停用词的字符可能用？代替
 
 针对每一个用例输出词频最高词出现的次数，停用词不统计，字母大小写认为相同
 1<=M<=10
 1<=N<=10000
 1<=K<=200
 
 
 2
 12 A tidy tiger tied a tie tighter to tidy her tiny tail
 1 a
 16 A big black bug bit a big black bear made the big black bear bleed blood
 2 b?? b???
 
 
 2
 3
 */

#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;


bool cmp(const pair<string, int> &p1, const pair<string, int> &p2){
    return p1.second > p2.second;
}

bool check(string str1, string str2){
    if(str1.length() == str2.length()){
        for(int i = 0; i < str1.length(); i++){
            if(str1[i] == str2[i] || str2[i] == '?'){
                continue;
            } else {
                return false;
            }
        }
    } else {
        return false;
    }
    return true;
}

int M, N, K;
int main(){
    cin >> M;
    for(int i = 0; i < M; i++){
        cin >> N;
        map<string, int> um;
        for(int j = 0; j < N; j++){
            string str;
            cin >> str;
            transform(str.begin(), str.end(), str.begin(), ::tolower);
            um[str]++;
        }
        vector<pair<string, int>> all;
        for(auto [k, v] : um){
            all.push_back(make_pair(k, v));
        }
        sort(all.begin(), all.end(), cmp);

        cin >> K;
        vector<string> words(K);
        for(int j = 0; j < K; j++){
            cin >> words[j];
            transform(words[j].begin(), words[j].end(), words[j].begin(), ::tolower);
        }
        
        for(auto [str, cnt] : all){
            bool flag = false;
            for(int j = 0; j < K; j++){
                if(check(str, words[j])){
                    flag = true;
                    break;;
                }
            }
            if(!flag){
                cout << cnt << endl;
                break;
            }
        }

    }
    
    return 0;
}

