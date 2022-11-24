/*
* Ͱ���򣨷ǱȽ��������㷨��
* ��������������棬���ú���ӳ���ϵ������ӳ�䵽��ͬ��Ͱ��
* 1. ��ͬͰ����Ҫ�������򣬲�ͬ�����㷨��Ӱ���㷨����
* 2. ���ս����Ͱ����ϲ�
* 
* ����
* ʱ�临�Ӷȣ�O(n+k)
* �ռ临�Ӷȣ�O(k)
* �ȶ��ԣ��ȶ�
* �洢��ʽ��������������������洢
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
		// ȡ��С���ֵ
		int min = nums[0], max = nums[0];
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] < min) {
				min = nums[i];
			}
			if (nums[i] > max) {
				max = nums[i];
			}
		}

		// ����Ͱ����Ϊ10
		int bucketSize = 10;
		int bucketCount = ceil(double(max - min + 1) / double(bucketSize));
		vector< vector<int> > buckets(bucketCount);
		for (int i = 0; i < nums.size(); i++) {
			int index = (nums[i] - min) / bucketSize;
			buckets[index].push_back(nums[i]);
		}

		// Ͱ����
		for (int i = 0; i < bucketCount; i++)
		{
			quickSort(buckets[i], 0, buckets[i].size() - 1);
		}

		// �ϲ�Ͱ
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