/*
* ���ֲ��ң���������
* 1. ���������޿�ȡ��Ŀ������������
* 2. ������ȷ�������r-lһ�����������С���������λ
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	double solve(double x) {
		double l = -10000;
		double r = 10000;
		// һ���ڱ���С��λ���������λ
		while (r - l > 1e-8) {
			double mid = (l + r) / 2;
			// ע��C++��^��ʾ���
			if (mid * mid * mid >= x) {
				r = mid;
			}
			else {
				l = mid;
			}
		}
		return r;
	}
};

int main() {
	double x;
	cin >> x;
	printf("%6f\n", Solution().solve(x));
	return 0;
}