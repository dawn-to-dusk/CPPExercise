/*
* 差分
* 差分相当于前缀和的逆运算
* A （B的）前缀和 A[i] = A[i-1] + a[i]
* B （A的）差分 B[i] = A[i] - A[i-1]
* 
* 前缀和方便计算B序列[l,r]的区间和
* 差分方便计算A序列[l,r]区间元素 + c
*  - 当A序列[l,r]区间每个元素+c，意味着B序列中：B[l]+C, B[r+1]-c
*  - 初始情况（根据初始A推B）：每拿到一个A[i]的值a相当于B[i] + a, B[i+1] - a
*  - A序列进行区间+c操作时，只需要改动B序列的l和r+1，再重新计算前缀和即可
*/

#include<iostream>
#include<vector>
using namespace std;

void insert(vector<int>& B, int l, int r, int c) {
	B[l] += c;
	if (r + 1 < B.size()) {
		B[r + 1] -= c;
	}
}

int main() {
	int n, m;
	cin >> n >> m;

	// 前缀和
	vector<int> A(n+1, 0);
	// 差分
	vector<int> B(n+1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		insert(B, i, i, A[i]);
	}

	for (int i = 0; i < m; i++) {
		int l, r, c;
		cin >> l >> r >> c;
		insert(B, l, r, c);
	}

	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += B[i];
		cout << sum << " ";
	}
	cout << endl;
	return 0;
}
