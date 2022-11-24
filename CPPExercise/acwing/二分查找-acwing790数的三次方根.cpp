/*
* 二分查找（浮点数）
* 1. 建议上下限可取题目给出的上下限
* 2. 浮点数确定结果的r-l一般在题给保留小数后面加两位
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	double solve(double x) {
		double l = -10000;
		double r = 10000;
		// 一般在保留小数位数后面加两位
		while (r - l > 1e-8) {
			double mid = (l + r) / 2;
			// 注意C++中^表示异或
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