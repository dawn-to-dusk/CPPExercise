/*
* 分治法
* 
* 注意，数据量可能超过1e9，结果值建议使用unsigned long
*/

#include<iostream>
#include<vector>
using namespace std;

unsigned long get_pairs(vector<int>& nums, int l, int r) {
	if (l >= r) {
		return 0;
	}

	int mid = (l + r + 1) >> 1;
	unsigned long count = 0;
	int L_start = l, L_end = mid - 1;
	int R_start = mid, R_end = r;
	count += get_pairs(nums, L_start, L_end);
	count += get_pairs(nums, R_start, R_end);

	int i = L_start, j = R_start;
	vector<int> tmp;
	while (i <= L_end && j <= R_end) {
		if (nums[i] <= nums[j]) {
			tmp.push_back(nums[i++]);
		}
		else {
			// 左边最小值比右边最小值大，故左边所有值均大于右边最小值，count直接加上一个左区间长度
			tmp.push_back(nums[j++]);
			count += (L_end - i + 1);
		}
	}
	while (i <= L_end) {
		tmp.push_back(nums[i++]);
	}
	while (j <= R_end) {
		tmp.push_back(nums[j++]);
	}

	for (int i = L_start, j = 0; i <= R_end; i++, j++) {
		nums[i] = tmp[j];
	}
	return count;
}

int main() {
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	cout << get_pairs(nums, 0, n - 1) << endl;

	return 0;
}