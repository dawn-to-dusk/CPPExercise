/*
* 基数排序（非比较型排序算法）
* 
* 基数排序 & 桶排序 & 计数排序
* 这三种排序算法都用到了桶的概念：
* - 计数排序：每个桶存储单一键值（比如计数数组的第i位只存储值为i的元素个数）
* - 桶排序：每个桶存储一定范围内的数值（比如某个桶只存储0-10之间的元素）
* - 基数排序：根据键值的每位数据来分配桶（比如先按个位数的值分配桶即按个位数排序，再按十位数的值来分配桶即按十位数排序）
* 
* 性能
* 时间复杂度：O(n*k)
* 空间复杂度：O(n*k)
* 稳定性：稳定
* 存储方式：数组或链表，存在索引存储
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> sortArray(vector<int> nums){
		radixSort(nums);
		return nums;
	}

	int maxBit(vector<int> nums) {
		if (nums.size() <= 0) {
			return 0;
		}
		int max = nums[0];
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] > max) {
				max = nums[i];
			}
		}

		int res = 0;
		while (max != 0) {
			max = max / 10;
			res++;
		}
		return res;
	}

	// 不考虑负数的简单版本
	void radixSortUnsigned(vector<int>& nums) {
		// 最大位数
		int nBit = maxBit(nums);
		// 存每轮排序后的数组
		vector<int> tmp(nums.size());
		// 位数计数数组
		int count[10];

		for (int i = 1, radix = 1; i <= nBit; i++, radix = radix * 10) {
			// 进行基数为i的一次计数排序

			// 清空计数数组
			for (int j = 0; j < 10; j++) {
				count[j] = 0;
			}

			// 遍历数组
			for (int j = 0; j < nums.size(); j++) {
				// 取其i位数值
				int index = nums[j] / radix % 10;
				count[index]++;
			}
			// 计数数组向前累加，得到该数值真正所在的位置
			for (int j = 1; j < 10; j++) {
				count[j] += count[j - 1];
			}
			// 按count计数数组重排数组，逆向重排
			for (int j = nums.size() - 1; j >= 0; j--) {
				int index = nums[j] / radix % 10;
				// 当前数的i位为index，按i位排是在第count[index]位
				// count[index]-1 减一是因为排在第一的是下标是0
				tmp[count[index] - 1] = nums[j];
				count[index]--;
			}

			// 临时数组赋值
			for (int j = 0; j < nums.size(); j++) {
				nums[j] = tmp[j];
			}

			/*for (int i = 0; i < nums.size(); i++) {
				cout << nums[i] << " ";
			}
			cout << endl;*/

		}
	}

	// 考虑负数
	void radixSort(vector<int>& nums) {
		// 0 & 正数
		vector<int> nums1;
		// 负数
		vector<int> nums2;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] >= 0) {
				nums1.push_back(nums[i]);
			}
			else {
				nums2.push_back(0 - nums[i]);
			}
		}

		radixSortUnsigned(nums1);
		radixSortUnsigned(nums2);

		int i = 0;
		for (int j = nums2.size() - 1; j >= 0; j--) {
			nums[i++] = 0 - nums2[j];
		}
		for (int j = 0; j < nums1.size(); j++) {
			nums[i++] = nums1[j];
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