/*
* 二分查找（整数二分）
* 一般是查找符合某一单调性（非必要）的序列中的某个值
* 1. 取中点mid = (l + r) >> 1
* 2. 根据check(mid)判断元素在左右哪个区间，并进行l/r调整
* 3. l==r时取到结果
* 
* 注意：
* 1. mid计算方式：当区间调整存在l=mid时，mid = (l + r + 1) >> 1，如果不加一，可能出现l与mid相等，那么l=mid区间调整无效
* 2. 取不到结果的时候可能在最后跳出循环时出现l>r，那么直接在数组中取值可能会溢出，因为mid可能取到序列边界值，加一或减一后下标可能溢出
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	void solve(vector<int> nums, vector<int> query) {
		for (int i = 0; i < query.size(); i++) {
			int s = getStart(nums, query[i]);
			int e = -1;
			if (s != -1) {
				e = getEnd(nums, query[i]);
			}
			cout << s << " " << e << endl;
		}
	}

	// 获取起始位置
	int getStart(vector<int> nums, int val) {
		int left = 0;
		int right = nums.size() - 1;
		while (left < right) {
			int mid = (left + right) >> 1;
			if (nums[mid] == val) {
				right = mid;
			}
			else if (nums[mid] > val) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		if (left > right || nums[left] != val) {
			return -1;
		}
		else {
			return left;
		}
	}
	// 获取终止位置
	int getEnd(vector<int> nums, int val) {
		int left = 0;
		int right = nums.size() - 1;
		while (left < right) {
			// ！！！注意此处需要加一
			// 如果不加一，可能出现left==mid==left，if的true分支无效陷入死循环
			int mid = (left + right + 1) >> 1;
			if (nums[mid] == val) {
				left = mid;
			}
			else if (nums[mid] > val) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		if (left > right || nums[left] != val) {
			return -1;
		}
		else {
			return left;
		}
	}
};

int main() {
	int n, q;
	cin >> n >> q;
	// 升序数列
	vector<int> nums(n);
	// 查询
	vector<int> query(q);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	for (int i = 0; i < q; i++) {
		cin >> query[i];
	}

	// 查询每个查询元素的起始位置与终止位置
	Solution().solve(nums, query);

	return 0;
}