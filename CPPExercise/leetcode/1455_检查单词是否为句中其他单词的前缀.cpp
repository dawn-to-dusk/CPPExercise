//
//  1455_检查单词是否为句中其他单词的前缀.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/8/21.
//

#include<iostream>
#include<string.h>
using namespace std;

bool isPrefix(string a, string b){
    if(a.length() < b.length()){
        return false;
    }
    for(int i = 0; i < a.length(); i++){
        if(i >= b.length()){
            break;
        }
        if(a[i] != b[i]){
            return false;
        }
    }
    return true;
}

int isPrefixOfWord(string sentence, string searchWord) {
    int count = 1;
    while(sentence.length() != 0){
        int pos = sentence.find(" ");
        if(pos == -1){
            pos = sentence.length();
        }
        string word = sentence.substr(0, pos);
        if(isPrefix(word, searchWord)){
            return count;
        } else {
            if(pos >= sentence.length()){
                break;
            }
            sentence = sentence.substr(pos+1, sentence.length() - pos - 1);
            count++;
        }
    }
    return -1;
}

int main(){
    string sentence = "1234 5678";
    string searchWord = "5678";
    cout << isPrefixOfWord(sentence, searchWord) << endl;
    return 0;
}
