//
///*
// 4 5
// 2
// + 1
// - 3
//
// 1 < n < 10^5
// */
//
//#include<iostream>
//using namespace std;
//
//
//int main(){
//    long long a, b;
//    int n;
//    cin >> a >> b >> n;
//
//    bool flag = false;
//    if(a < b){
//        long long tmp = a;
//        a = b;
//        b = tmp;
//        flag = true;
//    }
//
//    for(int i = 0; i < n; i++){
//        char op;
//        long long x;
//        cin >> op >> x;
//        switch (op) {
//            case '+':
//                if(x >= 0){
//                    a += x;
//                } else {
//                    b += x;
//                }
//
//                break;
//            default:
//                if(x >= 0){
//                    b -= x;
//                } else {
//                    a -= x;
//                }
//
//                break;
//        }
//    }
//
//    if(flag){
//        cout << b << ' ' << a << endl;
//    } else {
//        cout << a << ' ' << b << endl;
//    }
//
//    return 0;
//}




/*
 CCABCC
 3
 2 A
 3 B
 2 A
 C(2)A(21)B(11)C(2)
 */
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

struct Item{
    int id;
    char c;
    int len;
};

vector<Item> is;
//unordered_map<int, char> um;
string str;
int k;

bool cmp(const Item &a, const Item &b){
    return a.len < b.len;
}

bool cmp1(const Item &a, const Item &b){
    return a.id < b.id;
}
int main(){
    cin >> str;
    cin >> k;
    
    char pre = str[0];
    int len = 1;
    int id = 1;
    
    if(str.length() == 0){
        cout << endl;
        return 0;
    } else if(str.length() == 1){
        Item it;
        it.id = id;
        it.c = pre;
        it.len = len;
        is.emplace_back(it);
    } else {
        for(int i = 1; i < str.length(); i++){
            if(str[i] == pre){
                len++;
                if(i == str.length() - 1){
                    Item it;
                    it.id = id;
                    it.c = pre;
                    it.len = len;
                    is.emplace_back(it);
                    //um[id] = pre;
                }
            } else{
                Item it;
                it.id = id;
                it.c = pre;
                it.len = len;
                is.emplace_back(it);
                //um[id] = pre;
                pre = str[i];
                len = 1;
                id++;
            }
        }
    }
    
    
    for(int i = 0; i < k; i++){
        sort(is.begin(), is.end(), cmp);
        is[0].len += 10;
        cout << is[0].id << " " << is[0].c << endl;
    }
    
    sort(is.begin(), is.end(), cmp1);
    for(int i = 0; i < is.size(); i++){
        cout << is[i].c << "(" << is[i].len <<")";
    }
    cout << endl;
    return 0;
    
    
}

