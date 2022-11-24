/*
* 堆排序
* 1. 构造初始化大顶堆
*  - 从最后一个分支节点开始筛选（i=n/2即为最后一个分支节点，0下标不使用）
*  - 筛选流程：确保当前分支节点比其左右子节点大（左子节点i*2，右子节点i*2+1）,逐层向上筛选当前分支节点的父节点
* 2. 大顶堆构造好后根节点即为当前最大节点，每次调换根节点与最后一个节点的位置（将最大值放到最后），得到去掉最后一个节点后的新堆，再次筛选大顶堆
* 
* 性能
* 时间复杂度：O(nlogn)
* 空间复杂度：O(1)
* 稳定性：不稳定
* 存储方式：数组，排序过程中用下标按序搜索，所以用顺序存储
* 
* 注意：堆排序不计0位置，所以代码中涉及下标的地方都减一了
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> sortArray(vector<int> nums) {
		heapSort(nums);
		return nums;
	}

	// cur 当前筛选的分支节点
	// end 当前堆的最后一个节点
	void shift(vector<int>& nums, int cur, int end) {
		int cur_k = cur * 2; // cur的左孩子

		// cur有左孩子，是个可以筛选的分支节点
		while (cur_k <= end) {
			// cur有右孩子 且 右孩子较大
			if (cur_k < end && nums[cur_k - 1] < nums[cur_k]) {
				cur_k++;
			}
			// 当前cur_k为cur左右孩子中的较大者

			if (nums[cur-1] >= nums[cur_k-1]) {
				// cur根节点最大，cur的筛选结束
				break;
			}
			else {
				// cur_k最大，将其设为根节点
				swap(nums[cur-1], nums[cur_k-1]);
				// 继续筛cur_k，cur_k是刚刚交换过去的，以cur_k为根的堆未必满足是大顶堆
				cur = cur_k;
				cur_k = cur_k * 2;
			}
		}
	}

	void heapSort(vector<int>& nums) {
		int n = nums.size();
		/*vector<int> nums(n + 1);
		for (int i = 1; i <= n; i++) {
			nums[i] = nums_tmp[i - 1];
		}*/


		// 初始化大顶堆
		for (int i = n / 2; i > 0; i--) {
			shift(nums, i, n);
		}

		int end = n;
		while (end > 1) {
			// 交换顶和最后一个元素
			swap(nums[0], nums[end-1]);
			// 得到去掉最后一个元素的新堆
			end--;
			// 除了根节点1是新的，其他是满足大顶堆的，所以只需要筛一次1
			shift(nums, 1, end);
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