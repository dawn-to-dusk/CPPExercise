
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<set>
using namespace std;

const int MAXN = 1000010;

vector<int> ans;
vector<int> ps;
vector<int> ps2;
vector<int> ps3;
vector<int> ps4;

bool isPrimer(int n){
    if(n <= 1){
        return false;
    } else if(n == 2 || n == 3){
        return true;
    } else if(n % 6 != 1 && n % 6 != 5){
        return false;
    }
    for(int i = 5; i * i <= n; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

void setPrimer(){
    for(int i = 2; i < 1000; i++){
        if(isPrimer(i)){
            ps.push_back(i);
            int tmp = i * i;
            if(tmp <= MAXN){
                ps2.push_back(tmp);
                tmp *= i;
                if(tmp <= MAXN){
                    ps3.push_back(tmp);
                    tmp *= i;
                    if(tmp <= MAXN){
                        ps4.push_back(tmp);
                    }

                }

            }

        }
    }
}

set<int> res;
void setNum(){
    for(int i = 0; i < ps2.size(); i++){
        if(ps2[i] >= MAXN){
            break;
        }
        for(int j = 0; j < ps3.size(); j++){
            if(ps2[i] + ps3[j] >= MAXN){
                break;
            }
            for(int k = 0; k < ps4.size(); k++){
                if(ps2[i] + ps3[j] + ps4[k] <= MAXN){
                    res.insert(ps2[i] + ps3[j] + ps4[k]);
                } else {
                    break;
                }
            }
        }
    }
    sort(res.begin(), res.end());
}

int getNum(int n){
    int cnt = 0;
    for(auto i:res){
        if(n >= i){
            cnt++;
        } else {
            break;
        }
    }
    return cnt;
}

int main(){
    setPrimer();
    setNum();
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        cout << getNum(n) << endl;
    }
    return 0;
}


