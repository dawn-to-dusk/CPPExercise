/*
* 差分矩阵
* A 前缀和矩阵
* B 差分矩阵
* 
* 当A(i,j)+c时
*  - B(i,j)+c
*  - B(i,j+1)-c
*  - B(i+1,j)-c
*  - B(i+1,j+1)+c
* 当A(li,lj)-A(ri,rj)+c时，
*  - B(li, lj) + c
*  - B(ri+1, lj) - c
*  - B(li, rj+1) - c
*  - B(ri+1, rj+1) + c
* 
* 注意下标加一到边界时不能溢出
*/
#include<iostream>
#include<vector>
using namespace std;

void insert(vector< vector<int> >& B, int li, int lj, int ri, int rj, int val) {
	B[li][lj] += val;
	if (ri + 1 < B.size()) {
		B[ri + 1][lj] -= val;
	}
	if (rj + 1 < B[0].size()) {
		B[li][rj + 1] -= val;
	}
	if (ri + 1 < B.size() && rj + 1 < B[0].size()){
		B[ri + 1][rj + 1] += val;
	}
}

int main() {
	int n, m, q;
	cin >> n >> m >> q;
	vector< vector<int> > A(n+1, vector<int>(m+1, 0));
	vector< vector<int> > B(n+1, vector<int>(m+1, 0));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> A[i][j];
			insert(B, i, j, i, j, A[i][j]);
		}
	}

	for (int i = 0; i < q; i++) {
		int x1, y1, x2, y2, c;
		cin >> x1 >> y1 >> x2 >> y2 >> c;
		insert(B, x1, y1, x2, y2, c);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			A[i][j] = A[i - 1][j] + A[i][j - 1] - A[i - 1][j - 1] + B[i][j];
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
}