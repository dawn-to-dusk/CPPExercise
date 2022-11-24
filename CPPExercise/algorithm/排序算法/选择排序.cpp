/*
* 选择排序
* 前面逐渐有序，每次从后面的无序数列中找最大或最小继续添加到前面有序数列中
* 
* 1.找到序列中最小（大）的元素与队首（尾）交换
* 2.循环上一步
* 
* 性能
* 时间复杂度 O(n^) 永远时O(n^)（应该是最差的排序算法把）
* 空间复杂度 O(1)
* 稳定性 不稳定
* 存储方式：数组或链表均可
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> sortArry(vector<int>& nums) {
		select_sort(nums);
		return nums;
	}

	void select_sort(vector<int>& nums) {
		for (int i = 0; i < nums.size() - 1; i++) {
			int min = i;
			for (int j = i + 1; j < nums.size(); j++) {
				if (nums[j] < nums[min]) {
					min = j;
				}
			}
			swap(nums[i], nums[min]);
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
	vector<int> res = Solution().sortArry(nums);
	for (int i = 0; i < n; i++) {
		cout << res[i] << " ";
	}
	return 0;
}