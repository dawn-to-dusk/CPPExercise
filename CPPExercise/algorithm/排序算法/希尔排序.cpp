/*
* 希尔排序（插入排序改进，组内采用直接插入排序）
* 1.将序列按一定增量分组，对于每一组进行插入排序
* 2.增量逐渐减小为1，最终就只剩下一组，进行最后一轮插入排序
* 
* 性能
* 时间复杂度：O(nlogn)，最坏O(n^)
* 空间复杂度：O(1)
* 稳定性：不稳定
* 存储方式：数组，增量是按下标顺序的
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> sortArray(vector<int> nums) {
		shellSort(nums);
		return nums;
	}

	void shellSort(vector<int>& nums) {
		// x为增量，增量成倍减小至1
		for (int  x = nums.size() /2; x > 0; x /= 2) {
			// 遍历增量为x的每个分组的插入排序，从下标x开始的分组开始（相当于插入排序从下标1开始往前找位置）
			for (int i = x; i < nums.size(); i++) {
				// 下标i所在分组的一趟插入
				int j = i;
				while (j - x >= 0 && nums[j] < nums[j - x]) {
					swap(nums[j], nums[j - x]);
					j -= x;
				}
			}
		}
	}
};

int main(){
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
}