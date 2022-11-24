//
//  1_零件组装.cpp
//  CPPExercise
//
//  Created by Baozhu Fang on 2022/9/19.
//

/*
 小明管理了一家工厂。该工厂生产一种大型机械，需要由四种零件组装完成。我们不妨称这四种零件为A，B，C，D。
 由于生产机械需要保证产品的质量，工厂对每个零件会进行检测，量化出每个零件的评分。评分当然有一个合格的分数(我们不妨假设它是x)，当零件评分大于x的时候，该零件才是合格的。
 四个分别合格的零件ABC，D可以组装成一个合格的大型机械。现在小明想知道当前产出的这些零件一共可以组装成多少合格的大型机械?
 请注意:每个零件至多只能用于一个大型机械的组装，不能反复组装。

 输入描述
 第一行五个正整数，前四个正整数a1a2,a3,a4分别表示有a1个零件A，a2个零件B， a3个零件C，a4个零件D，第五个正整数x表示合格的零件评分需要大于x。接下来4行:
 第二行有a1个空格分开的数字，分别表示这a1个零件A的评分。
 第三行有a2个空格分开的数字，分别表示这a2个零件B的评分。
 第四行有a3个空格分开的数字，分别表示这a3个零件C的评分。
 第五行有a4个空格分开的数字，分别表示这a4个零件D的评分。
 输出描述
 输出一个数， 表示可以组装成的大型机械的数量。
 
 该组样例中所有零件均符合标准，但只能组装完成一个大型机械。数据范围和说明
 1 <= al, a2, a3, a4 <= 1000
 对全体数据均保证1<=x<=1000，每个零件的评分也在[1，1000]之间。
 */

/*
 1 2 2 1 2
 4
 7 7
 6 6
 8
 1
 */
// ak

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int N = 1010;
int a, b, c, d, x;
int na, nb, nc, nd;

int main(){
    cin >> a >> b >> c >> d >> x;
    for(int i = 0; i < a; i++){
        int tmp;
        cin >> tmp;
        if(tmp > x){
            na++;
        }
    }
    for(int i = 0; i < b; i++){
        int tmp;
        cin >> tmp;
        if(tmp > x){
            nb++;
        }
    }
    for(int i = 0; i < c; i++){
        int tmp;
        cin >> tmp;
        if(tmp > x){
            nc++;
        }
    }
    
    for(int i = 0; i < d; i++){
        int tmp;
        cin >> tmp;
        if(tmp > x){
            nd++;
        }
//        if(tmp > x && na > 0 && nb > 0 && nc > 0){
//            na--;
//            nb--;
//            nc--;
//            res++;
//        }
    }
    
    int res = min(min(na,nb), min(nc, nd));
    cout << res << endl;
    return 0;
    
}
