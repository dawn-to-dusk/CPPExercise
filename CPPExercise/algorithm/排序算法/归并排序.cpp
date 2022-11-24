/* 
* 归并排序（分治法）
* 
* 递归算法：
* 1.中点分界
* 2.递归左右区间进行归并排序
* 3.左右有序区间合二为一 ——重点
* 
* 非递归算法：
* 1.从区间长度为1开始，讲序列划分为多个左右区间子序列
* 2.区间长度成倍增长，合并左右子序列
* 
* 性能
* 时间复杂度：O(nlogn) ——归并排序对原始数据的排序状态不敏感，在数据总量较大时最能体现出它的时间性能优势
* 空间复杂度：O(n) ——归并排序中有新序列和原序列，故需要两个序列空间
* 稳定性：稳定，相等元素排序后位置不变
* 存储方式：数组或链表
*/

#include<iostream>
#include<vector>
using namespace std;

// 递归
void merge_sort_1(vector<int>& nums, int l, int r) {
	if (l == r) {
		return;
	}

	int mid = (l + r + 1) >> 1;
	merge_sort_1(nums, l, mid - 1);
	merge_sort_1(nums, mid, r);

	vector<int> tmp;
	int i = l, j = mid;
	while (i <= mid - 1 && j <= r) {
		if (nums[i] <= nums[j]) {
			tmp.push_back(nums[i]);
			i++;
		}
		else {
			tmp.push_back(nums[j]);
			j++;
		}
	}
	while (i <= mid - 1) {
		tmp.push_back(nums[i]);
		i++;
	}
	while (j <= r) {
		tmp.push_back(nums[j]);
		j++;
	}
	for (int i = l, j = 0; i <= r; i++, j++) {
		nums[i] = tmp[j];
	}
}

// 非递归
void merge_sort_2(vector<int> &nums) {
	// 区间长度逐倍增长，每个区间长度为i
	for (int i = 1; i <= nums.size(); i *= 2) {
		// 逐个遍历区间[j, j+i*2]
		int L_start = 0, L_end = 0;
		int R_start = 0, R_end = 0;
		for (L_start = 0; L_start < nums.size() - i; L_start = R_end) {
			// 左区间（左闭右开）
			L_end = L_start + i;
			// 右区间
			R_start = L_start + i; 
			R_end = R_start + i;
			if (R_end > nums.size()) {
				R_end = nums.size();
			}

			vector<int> tmp;
			int a = L_start, b = R_start;
			while (a < L_end && b < R_end) {
				if (nums[a] <= nums[b]) {
					tmp.push_back(nums[a]);
					a++;
				}
				else {
					tmp.push_back(nums[b]);
					b++;
				}
			}
			while (a < L_end) {
				tmp.push_back(nums[a]);
				a++;
			}
			while (b < R_end) {
				tmp.push_back(nums[b]);
				b++;
			}
			for (int j = L_start, k = 0; j < R_end; j++, k++) {
				nums[j] = tmp[k];
			}
		}
	}
}

int main() {
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	//merge_sort_1(nums, 0, n - 1);
	merge_sort_2(nums);

	for (int i = 0; i < n; i++) {
		cout << nums[i] << " ";
	}
	return 0;
}