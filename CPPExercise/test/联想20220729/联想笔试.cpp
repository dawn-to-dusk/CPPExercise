//
//  main.cpp
//  Tmp
// 海康威视
//
//  Created by Baozhu Fang on 2022/7/28.

// 6
//in 00:40:14
//out 04:48:37
//in 07:06:20
//out 09:17:53
//in 10:14:44
//out 10:36:29
//

#include <iostream>
#include <vector>
using namespace std;

//vector<int> getTime(string str){
//    vector<int> time(3);
//    int tmp = 0;
//    int j = 0;
//    for(int i = 0; i < str.length(); i++){
//        if(str[i]!=':'){
//            tmp = tmp * 10 + (str[i] - '0');
//        } else {
//            time[j++] = tmp;
//            tmp = 0;
//        }
//    }
//    time[j] = tmp;
//
//    return time;
//}
//
//void addTime(vector<int> &time, vector<int> in, vector<int> out){
//    int t = 0;
//    vector<int> tmp(3, 0);
//    for(int i = 2; i >= 0; i--){
//        tmp[i] = out[i] - in[i] - t;
//        if(out[i] < in[i]){
//            tmp[i] += 60;
//            t = 1;
//        } else {
//            t = 0;
//        }
//    }
//
//    for(int i = 2; i >= 0; i--){
//        int newTime = time[i] + tmp[i] + t;
//        if(newTime / 60 > 0){
//            t = 1;
//        } else {
//            t = 0;
//        }
//        time[i] = newTime % 60;
//    }
//}
//
//int main(int argc, const char * argv[]) {
//    int n;
//    cin >> n;
//    vector<int> time(3, 0);
//    vector<int> in(3, 0);
//    vector<int> out(3, 0);
//
//    string lastFlag;
//    for(int i = 0; i < n; i++){
//        string flag, str;
//        cin >> flag >> str;
//
//        if(flag == lastFlag){
//            continue;
//        } else {
//            if(flag == "in"){
//                in = getTime(str);
//            } else {
//                if(lastFlag == ""){
//                    continue;
//                }
//                out = getTime(str);
//                addTime(time, in, out);
//            }
//        }
//        lastFlag = flag;
//    }
//
//    vector<string> res(3);
//    for(int i = 0; i < 2; i++){
//        if(time[i] < 10){
//            cout << "0" ;
//        }
//        cout << time[i] << ":";
//    }
//    if(time[2] < 10){
//        cout << "0" ;
//    }
//    cout << time[2] << endl;
//
//    return 0;
//}

//string getInstr(string str, int start){
//    string instr;
//    for(int i = start; i < 3; i++){
//        instr += str[i];
//    }
//    return instr;
//}
//
int main(){
    int n;
    cin >> n;
    string str;
    cin >> str;

    if(n == 1){
        return 0;
    }
    if (n == 2){
        return 0;
    }
    if(str == "rbr" || str == "brb"){
        return 1;
    }
    vector<char> chars(n);
    int start = 0;
    int count = 0;
    while(start + 2 < n){======lhjk;
        if(start == 0){
            if(getInstr(str, start) == "rbb" || getInstr(str, start) == "brr"){
                count++;
            }
        }else if(start + 2 == n-1){
            if(getInstr(str, start) == "bbr" || getInstr(str, start) == "rrb"){
                count++;
                if(count > 1){
                    return count;
                } else {
                    return 0;
                }
            }
        }

        if(getInstr(str,start) == "rbr"){
            str[start + 1] = 'r';
            count++;
        } else if(getInstr(str, start) == "brb"){
            str[start + 1] = 'b';
            count++;
        }
        start++;
    }
    cout << count << endl;

    return 0;
}
