/*
* 前缀和
* Si = Si-1 + ai
* 
* 作用：方便计算[l,r]的区间和 M[l,r] = Sr - Sl-1 
* 注意：为了方便区间和计算统一性，可以将下标从1开始计起，S0 = 0
*/

#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> nums(n);
	vector<int> S(n + 1, 0);
	S[0] = 0;
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
		S[i + 1] = S[i] + nums[i];
	}
	vector< vector<int>> query(m, vector<int>(2));
	for (int i = 0; i < m; i++) {
		int l, r;
		cin >> l >> r;
		cout << S[r] - S[l - 1] << endl;
	}
	return 0;
}