/*
 T1 分配捐款
 某村共有m个村民，所有村民的资产均不相同，村长收到一笔n元的捐款，村长计划把该捐款分给村民，使尽可能多的村民拥有相同的资产，剩余的捐款将保留做为集体资产。

 请帮村长分配捐款，使得在最多村民刚好拥有相同资产的前提下，并剩余尽可能少的捐款，如果某村民不能通过分配捐款拥有相同资产，则不予分配，如三个村民的资产是10,3,1，待分配捐款为8，则分配结果为10,10,1，剩余1的捐款无法使第3个村民的资产达到10，所以不予分配。
 
 输入村民数目m，然后输入m个数字作为村民的资产金额，最后输入一个捐款金额n
 m<1e4，n<1e8，a[i]<1e6
 输出拥有相同资产的村民数和剩余捐款数
 input:
 5
 2 9 3 1 6
 4

 output:
 3 1
 
 示例2
 input:
 3
 10 3 1
 8

 output:
 2 1
 
 
 题目隐藏条件：
 - 最终每个人拿到的钱一定和某个人的原始资产一样多
 - 最终拿到的钱是原始资产排序后连续的村民

 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int m;
vector<int> nums;

int main(){
    cin >> n;
    nums.resize(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    cin >> m;
    
    sort(nums.begin(), nums.end());
    
    int l = 0;
    int sum = 0;
    int cnt = 1; // 最多人数
    int remain = m; // 最少余额
    for(int r = 0; r < n; r++){ // 循环增大右窗口
        sum += nums[r];
        while(nums[r] * (r - l + 1) - sum > m) {// 如果钱不够，循环增大左窗口以缩减
            sum -= nums[l];
            l++;
        }
        // 直到找到一个够的左窗口
        
        if(r - l + 1 > cnt){ // 人数增加，直接更新
            cnt = r - l + 1;
            remain = m - (nums[r] * (r - l + 1) - sum);
        } else if( r- l + 1 == cnt){ // 人数不增加，取余额小的
            remain = min(remain, m - (nums[r] * (r - l + 1) - sum));
        }
    }
    
    cout << cnt << " " << remain << endl;
}

