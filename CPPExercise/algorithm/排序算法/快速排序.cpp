/*
* 快速排序（分治法）
* 1. 确定分界点i：左边界、右边界、中点
* 2. 调整左右区间，使得左区间所有数值小于i，右区间所有数值大于i ——重点
* 3. 递归处理左右两区间 
* 
* 性能
* 时间复杂度：O(nlogn)-O(n^) ——对于无序序列快速排序时间性能较好；而对于有序序列，快速排序是最坏的排序情况
* 空间复杂度：O(logn) —— 需要一个栈来存放每一层递归调用的必要信息（递归永远不可能是常数空间）
* 稳定性：不稳定（两个相等元素在排序后位置可能发生变化）
* 存储方式：数组，顺序存储（查询较多）
* 快排每一趟能确定枢纽的最终位置
*/

#include<iostream>
#include<vector>
using namespace std;

void swap(vector<int> &nums, int i, int j) {
	int tmp = nums[i];
	nums[i] = nums[j];
	nums[j] = tmp;
}

void quick_sort(vector<int> &nums, int l, int r) {
	if (l >= r) {
		return;
	}
	int x = (l + r) >> 1;
	//int x = l;
	int Vx = nums[x];
	// ！！！注意取边界两侧值，因为do while每次会先做一个++/--
	// 如果不用do while，循环时当i和j的value相等时指针无法移动
	int i = l - 1, j = r + 1;
	while (i < j) {
		do i++;
		while (nums[i] < Vx);
		do j--;  
		while (nums[j] > Vx);
		if (i < j) {
			swap(nums, i, j);
		}
	}
	quick_sort(nums, l, j);
	quick_sort(nums, j + 1, r);
	// ！！！注意边界值
	// 如果边界值为l或者(l + r) >> 1，不能使用i-1和i，可能出现死循环
	// 如果边界值为r或者(l + r + 1) >> 1，不能使用j和j+1，可能出现死循环
	// 死循环指[0,1]区间左区间一直是[0,-1]右区间一直是[0,1]这种
}

int main() {
	int n;
	cin >> n;

	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	quick_sort(nums, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << nums[i] << " ";
	}

	return 0;
}