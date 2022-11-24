/*
* ǰ׺��
* Si = Si-1 + ai
* 
* ���ã��������[l,r]������� M[l,r] = Sr - Sl-1 
* ע�⣺Ϊ�˷�������ͼ���ͳһ�ԣ����Խ��±��1��ʼ����S0 = 0
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