/*
* ���
* ����൱��ǰ׺�͵�������
* A ��B�ģ�ǰ׺�� A[i] = A[i-1] + a[i]
* B ��A�ģ���� B[i] = A[i] - A[i-1]
* 
* ǰ׺�ͷ������B����[l,r]�������
* ��ַ������A����[l,r]����Ԫ�� + c
*  - ��A����[l,r]����ÿ��Ԫ��+c����ζ��B�����У�B[l]+C, B[r+1]-c
*  - ��ʼ��������ݳ�ʼA��B����ÿ�õ�һ��A[i]��ֵa�൱��B[i] + a, B[i+1] - a
*  - A���н�������+c����ʱ��ֻ��Ҫ�Ķ�B���е�l��r+1�������¼���ǰ׺�ͼ���
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

	// ǰ׺��
	vector<int> A(n+1, 0);
	// ���
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
