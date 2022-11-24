/*
* 对于可能存在K个数的区间进行快速排序
*/
#include<iostream>
#include<vector>
using namespace std;

void swap(vector<int>& nums, int i, int j) {
	int tmp = nums[i];
	nums[i] = nums[j];
	nums[j] = tmp;
}

void quick_choose(vector<int>& nums, int l, int r, int k) {
	if (l >= r) {
		return;
	}
	int x = nums[(l + r) >> 1];
	int i = l - 1;
	int j = r + 1;
	while (i < j) {
		do i++;
		while (nums[i] < x);
		do j--;
		while (nums[j] > x);
		if (i < j) {
			swap(nums, i, j);
		}
	}

	// 左区间 l, j 长度为 j - l + 1
	// 右区间j + 1, r

	if (j - l + 1 < k) {
		// 在右区间
		quick_choose(nums, j + 1, r, k - j + l - 1);
	}
	else if (j - l + 1 >= k) {
		// 在左区间
		quick_choose(nums, l, j, k);
	}
}

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	quick_choose(nums, 0, n - 1, k);
	cout << nums[k - 1] << endl;

	/*for (int i = 0; i < n; i++) {
		cout << nums[i] << " ";
	}*/
	return 0;
}