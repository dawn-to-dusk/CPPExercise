/*
* 桶排序（非比较型排序算法）
* 计数排序的升级版，利用函数映射关系将数据映射到不同的桶中
* 1. 不同桶中需要进行排序，不同排序算法会影响算法性能
* 2. 最终将多个桶按序合并
* 
* 性能
* 时间复杂度：O(n+k)
* 空间复杂度：O(k)
* 稳定性：稳定
* 存储方式：数组或链表，存在索引存储
*/

#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

class Solution {
public:
	vector<int> sortArray(vector<int> nums) {
		bucketSort(nums);
		return nums;
	}

	void quickSort(vector<int>& nums, int l, int r) {
		if (l >= r) {
			return;
		}
		int x = nums[(l + r + 1) >> 1];
		int i = l - 1;
		int j = r + 1;
		while (i < j) {
			do i++;
			while (nums[i] < x);
			do j--;
			while (nums[j] > x);
			if (i < j) {
				swap(nums[i], nums[j]);
			}
		}
		quickSort(nums, l, i - 1);
		quickSort(nums, i, r);
	}

	void bucketSort(vector<int>& nums) {
		// 取最小最大值
		int min = nums[0], max = nums[0];
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] < min) {
				min = nums[i];
			}
			if (nums[i] > max) {
				max = nums[i];
			}
		}

		// 设置桶容量为10
		int bucketSize = 10;
		int bucketCount = ceil(double(max - min + 1) / double(bucketSize));
		vector< vector<int> > buckets(bucketCount);
		for (int i = 0; i < nums.size(); i++) {
			int index = (nums[i] - min) / bucketSize;
			buckets[index].push_back(nums[i]);
		}

		// 桶排序
		for (int i = 0; i < bucketCount; i++)
		{
			quickSort(buckets[i], 0, buckets[i].size() - 1);
		}

		// 合并桶
		int k = 0;
		for (int i = 0; i < bucketCount; i++)
		{
			for (int j = 0; j < buckets[i].size(); j++)
			{
				nums[k++] = buckets[i][j];
			}
		}
	}
};

int main() {
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}

	vector<int> res = Solution().sortArray(nums);

	for (int i = 0; i < n; i++) {
		cout << res[i] << " ";
	}

	return 0;
}