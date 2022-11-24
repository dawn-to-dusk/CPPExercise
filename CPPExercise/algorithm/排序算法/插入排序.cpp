/*
* 插入排序
* 类似打斗地主，每次抓一张牌，从后往前比较，把新抓的牌放到合适大小的位置
* 
* 1. 将第一个元素当作有序数列，后续为无序数列
* 2. 每拿到一个新的元素，插入到该元素在有序数列中合适的位置
* 
* 性能
* 时间复杂度：O(n^) 最好的情况（有序）O(n)
* 空间复杂度：O(1)
* 稳定性：稳定
* 存储方式：数组或链表，插入较多的一般选择链表
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
	vector<int> sortArray(vector<int>& nums) {
		insertSort(nums);
		return nums;
	}

	void insertSort(vector<int>& nums) {
		for (int i = 1; i < nums.size(); i++) {
			int val = nums[i];
			for (int j = i - 1; j >= 0; j--) {
				if (nums[j] > val) {
					nums[j + 1] = nums[j];
					if (j == 0) {
						nums[j] = val;
						break;
					}
				}
				else {
					nums[j + 1] = val;
					break;
				}
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
		cout << nums[i] << " ";
	}
	return 0;
}