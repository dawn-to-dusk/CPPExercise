/*
* ð������
* ÿ�ΰѵ�ǰ����������������С�������������������������
* 
* 1.�Ƚ����ڵ�����Ԫ�أ��������ƶ���һ��ð�ݽ��������һ��Ԫ�����
* 2.��ȥ���һ��Ԫ��ѭ��ð��
* 
* ���ܣ�
* ʱ�临�Ӷȣ�O(n^)  ������������O(n)��������������O��n^��
* �ռ临�Ӷȣ�O(1) ԭ�ؽ������ݣ�����Ҫ�����¿ռ�
* �ȶ��ԣ��ȶ�
* �洢��ʽ�����飬�����ѯ����˳��洢
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> sortArray(vector<int>& nums) {
		bubble_sort(nums);
		return nums;
	}

	void swap(vector<int>& nums, int a, int b) {
		int tmp = nums[a];
		nums[a] = nums[b];
		nums[b] = tmp;
	}

	void bubble_sort(vector<int>& nums) {
		int n = nums.size();
		for (int i = 0; i < n - 1; i++) {
			bool flag = false;
			for (int j = 0; j < n - i - 1; j++) {
				if (nums[j] > nums[j + 1]) {
					swap(nums, j, j + 1);
					flag = true;
				}
			}
			if (!flag) {
				return;
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