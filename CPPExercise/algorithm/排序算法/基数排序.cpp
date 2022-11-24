/*
* �������򣨷ǱȽ��������㷨��
* 
* �������� & Ͱ���� & ��������
* �����������㷨���õ���Ͱ�ĸ��
* - ��������ÿ��Ͱ�洢��һ��ֵ�������������ĵ�iλֻ�洢ֵΪi��Ԫ�ظ�����
* - Ͱ����ÿ��Ͱ�洢һ����Χ�ڵ���ֵ������ĳ��Ͱֻ�洢0-10֮���Ԫ�أ�
* - �������򣺸��ݼ�ֵ��ÿλ����������Ͱ�������Ȱ���λ����ֵ����Ͱ������λ�������ٰ�ʮλ����ֵ������Ͱ����ʮλ������
* 
* ����
* ʱ�临�Ӷȣ�O(n*k)
* �ռ临�Ӷȣ�O(n*k)
* �ȶ��ԣ��ȶ�
* �洢��ʽ��������������������洢
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

	// �����Ǹ����ļ򵥰汾
	void radixSortUnsigned(vector<int>& nums) {
		// ���λ��
		int nBit = maxBit(nums);
		// ��ÿ������������
		vector<int> tmp(nums.size());
		// λ����������
		int count[10];

		for (int i = 1, radix = 1; i <= nBit; i++, radix = radix * 10) {
			// ���л���Ϊi��һ�μ�������

			// ��ռ�������
			for (int j = 0; j < 10; j++) {
				count[j] = 0;
			}

			// ��������
			for (int j = 0; j < nums.size(); j++) {
				// ȡ��iλ��ֵ
				int index = nums[j] / radix % 10;
				count[index]++;
			}
			// ����������ǰ�ۼӣ��õ�����ֵ�������ڵ�λ��
			for (int j = 1; j < 10; j++) {
				count[j] += count[j - 1];
			}
			// ��count���������������飬��������
			for (int j = nums.size() - 1; j >= 0; j--) {
				int index = nums[j] / radix % 10;
				// ��ǰ����iλΪindex����iλ�����ڵ�count[index]λ
				// count[index]-1 ��һ����Ϊ���ڵ�һ�����±���0
				tmp[count[index] - 1] = nums[j];
				count[index]--;
			}

			// ��ʱ���鸳ֵ
			for (int j = 0; j < nums.size(); j++) {
				nums[j] = tmp[j];
			}

			/*for (int i = 0; i < nums.size(); i++) {
				cout << nums[i] << " ";
			}
			cout << endl;*/

		}
	}

	// ���Ǹ���
	void radixSort(vector<int>& nums) {
		// 0 & ����
		vector<int> nums1;
		// ����
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