/*
* 计数排序（非比较型排序算法）
* 前提：输入数据是有确定范围的整数
* 1. 确定数据范围（最小最大值）
* 2. 统计数组中值为i的数的个数ni，作为计数数组的第i项的值
* 3. 计数数组向前累加，比如值C[2] = C[2] + C[1]，即可确定值2出现的位置
* 4. 反向填充数组，元素i放在数组的C[i]项，每取出一个元素，C[i]减1
* 
* 性能
* 时间复杂度：O(n+k)
* 空间复杂度：O(k)
* 稳定性：稳定
* 存储方式：数组或链表，存在索引存储
* 适合数据范围不大的数组
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> sortArray(vector<int> nums) {
		countSort(nums);
		return nums;
	}

	void countSort(vector<int> &nums) {
		int min = nums[0], max = nums[0];
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] > max) {
				max = nums[i];
			}
			if (nums[i] < min) {
				min = nums[i];
			}
		}

		int n = max - min + 1;
		vector<int> count(n);
		for (int i = 0; i < nums.size(); i++) {
			count[nums[i] - min]++;
		}
		int k = nums.size() - 1;
		for (int i = n - 1; i >=0; i--) {
			for (int j = 0; j < count[i]; j++) {
				nums[k--] = i + min;
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