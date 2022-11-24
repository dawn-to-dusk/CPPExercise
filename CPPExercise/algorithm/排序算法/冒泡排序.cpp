/*
* 冒泡排序
* 每次把当前无序数列中最大或最小的数交换到此无序数量的最后
* 
* 1.比较相邻的两个元素，大的向后移动，一趟冒泡结束后最后一个元素最大
* 2.除去最后一个元素循环冒泡
* 
* 性能：
* 时间复杂度：O(n^)  最好情况（正序）O(n)，最差情况（逆序）O（n^）
* 空间复杂度：O(1) 原地交换数据，不需要开辟新空间
* 稳定性：稳定
* 存储方式：数组，按序查询建议顺序存储
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> sortArray(vector<int>& nums) {
		bubble_sort(nums);
		return nums;
	}

	void swap(vector<int>& nums, int a, int b) {
		int tmp = nums[a];
		nums[a] = nums[b];
		nums[b] = tmp;
	}

	void bubble_sort(vector<int>& nums) {
		int n = nums.size();
		for (int i = 0; i < n - 1; i++) {
			bool flag = false;
			for (int j = 0; j < n - i - 1; j++) {
				if (nums[j] > nums[j + 1]) {
					swap(nums, j, j + 1);
					flag = true;
				}
			}
			if (!flag) {
				return;
			}
		}
	}

};


int main() {
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	vector<int> res = Solution().sortArray(nums);

	for (int i = 0; i < n; i++) {
		cout << res[i] << " ";
	}
	return 0;
}