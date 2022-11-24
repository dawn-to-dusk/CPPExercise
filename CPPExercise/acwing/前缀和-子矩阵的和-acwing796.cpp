/*
* 子矩阵的和（acwing-796）
* 二维前缀和
*/

#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n, m, q;
	cin >> n >> m >> q;
	vector< vector<int> > a(n + 1, vector<int>(m + 1, 0));
	//// 横向前缀和 N(i,j) = N(i, j-1) + a(i,j)
	//vector< vector<int> > N(n + 1, vector<int>(m + 1, 0));
	//// 纵向前缀和 M(i,j) = M(i-1, j) + a(i,j)
	//vector< vector<int> > M(n + 1, vector<int>(m + 1, 0));
	// 二维矩阵前缀和 S(i,j) = S(i-1, j-1) + N(i, j-1) + M(i-1, j) + a(i,j)
	vector< vector<int> > S(n + 1, vector<int>(m + 1, 0));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
			/*N[i][j] = N[i][j - 1] + a[i][j];
			M[i][j] = M[i - 1][j] + a[i][j];
			S[i][j] = S[i - 1][j - 1] + N[i][j - 1] + M[i - 1][j] + a[i][j];*/
			S[i][j] = S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1] + a[i][j];
		}
	}

	for (int i = 0; i < q; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << S[x2][y2] - S[x2][y1 - 1] - S[x1 - 1][y2] + S[x1 - 1][y1 - 1] << endl;
	}

	return 0;
}