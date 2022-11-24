/*
* �߾��ȼӼ��˳�
* 1. ��λ�洢�������У�0���꿪ʼ���λ��
* 2. ���ֶ�����ķ�����λ����
* 3. ע��һ������ĳ�����Ϊ����������divABΪ���Ǵ��������������һ����ȷ
*/
#include<iostream>
#include<vector>
using namespace std;

// A + B
vector<int> add(vector<int> a, vector<int> b) {
	vector<int> res;
	int t = 0;
	for (int i = 0; i < a.size() || i < b.size(); i++) {
		if (i < a.size()) {
			t += a[i];
		}
		if (i < b.size()) {
			t += b[i];
		}
	
		res.push_back(t % 10);
		t = t / 10;
	}
	if (t != 0) {
		res.push_back(t);
	}

	return res;
}

// A >= B ?
bool cmp(vector<int> a, vector<int> b) {
	if (a.size() > b.size()) {
		return true;
	}
	else if(a.size() < b.size()) {
		return false;
	} 

	for (int i = a.size() - 1; i >= 0; i--) {
		if (a[i] > b[i]) {
			return true;
		}
		else if (a[i] < b[i]) {
			return false;
		}
	}

	return true;
}

// A - B (A > B)
vector<int> sub(vector<int> a, vector<int> b) {
	vector<int> res;
	int t = 0;
	for (int i = 0; i < a.size(); i++) {
		// ��������ȥ��λ
		t = a[i] - t;
		if (i < b.size()) {
			t = t - b[i];
		}

		res.push_back((t + 10) % 10);
		if (t < 0) {
			t = 1;
		}
		else {
			t = 0;
		}
	}
	
	// ɾȥ�����ǰ��0
	while (res.size() > 1 && res.back() == 0) {
		res.pop_back();
	}
	return res;
}

// A * B
vector<int> mul(vector<int> a, vector<int> b) {
	vector< vector<int>> tmp(b.size());
	for (int i = 0; i < b.size(); i++) {
		for (int j = 0; j < i; j++) {
			tmp[i].push_back(0);
		}

		int t = 0;
		for (int j = 0; j < a.size(); j++) {
			t += a[j] * b[i];
			tmp[i].push_back(t % 10);
			t = t / 10;
		}
		if (t != 0) {
			tmp[i].push_back(t);
		}
	}

	vector<int> res;
	res.push_back(0);
	for (int i = 0; i < tmp.size(); i++) {
		res = add(res, tmp[i]);
	}
	return res;
}

// A / b (�����Ǵ���)
vector< vector<int>> div(vector<int> a, int b) {
	int tmpA = 0;
	vector<int> res;
	for (int i = a.size() - 1; i >= 0; i--) {
		tmpA = tmpA * 10 + a[i];

		if (tmpA >= b) {
			res.insert(res.begin(), tmpA / b);
			tmpA = tmpA % b;
		}
		else {
			// ������0
			res.insert(res.begin(), 0);
		}
	}

	while (res.size() > 1 && res.back() == 0) {
		res.pop_back();
	}

	return vector< vector<int>>{res, vector<int> {tmpA}};
}

// A / B (����ҲΪ����)
vector< vector<int>> divAB(vector<int> a, vector<int> b) {
	vector<int> tmpA;
	vector<int> res;
	for (int i = a.size() - 1; i >= 0; i--) {
		tmpA.insert(tmpA.begin(), a[i]);
		// ���м��㲻����ǰ����
		while (tmpA.size() > 1 && tmpA.back() == 0) {
			tmpA.pop_back();
		}

		if (cmp(tmpA, b)) {
			for (int j = 1; j <= 9; j++) {
				vector<int> tmpB = mul(b, vector<int>{j});
				// tmpA һ������tmpB
				vector<int> remain = sub(tmpA, tmpB);
				if (cmp(remain, b)) {
					continue;
				}
				else {
					tmpA = remain;
					res.insert(res.begin(), j);
					break;
				}
			}
		}
		else {
			// ������0
			res.insert(res.begin(), 0);
		}
	}

	while (res.size() > 1 && res.back() == 0) {
		res.pop_back();
	}
	while (tmpA.size() > 1 && tmpA.back() == 0) {
		tmpA.pop_back();
	}

	return vector< vector<int>>{res, tmpA};
}

int getVal(vector<int> nums) {
	int res = 0;
	for (int i = nums.size() - 1; i >= 0; i--) {
		res = res * 10 + nums[i];
	}
	return res;
}

int main() {
	string strA, strB;
	cin >> strA >> strB;
	vector<int> a, b;

	for (int i = strA.length() - 1; i >= 0; i--) {
		a.push_back(strA[i] - '0');
	}
	for (int i = strB.length() - 1; i >= 0; i--) {
		b.push_back(strB[i] - '0');
	}

	// �ӷ�
	cout << "A + B = ";
	vector<int> res1 = add(a, b);
	for (int i = res1.size() - 1; i >= 0; i--) {
		cout << res1[i];
	}
	cout << endl;

	// ����
	cout << "A - B = ";
	vector<int> res2;
	if (cmp(a, b)) {
		res2 = sub(a, b);
		for (int i = res2.size() - 1; i >= 0; i--) {
			cout << res2[i];
		}
	}
	else {
		res2 = sub(b, a);
		cout << "-";
		for (int i = res2.size() - 1; i >= 0; i--) {
			cout << res2[i];
		}
	}
	cout << endl;

	// �˷�
	cout << "A * B = ";
	if (strA == "0" || strB == "0") {
		cout << 0 << endl;
	}
	else {
		vector<int> res3 = mul(a, b);
		for (int i = res3.size() - 1; i >= 0; i--) {
			cout << res3[i];
		}
		cout << endl;
	}

	// ���� ע��һ�����Ҫ��������Ǵ���
	cout << "A / b = ";
	if (getVal(b) > 10000) {
		cout << "����Ҳ�Ǵ���" << endl;
	}
	else {
		vector< vector<int>> res4 = div(a, getVal(b));
		for (int i = 0; i < res4.size(); i++) {
			for (int j = res4[i].size() - 1; j >= 0; j--) {
				cout << res4[i][j];
			}
			cout << " ";
		}
	}
	return 0;
}