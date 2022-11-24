/*
* ѡ������
* ǰ��������ÿ�δӺ����������������������С������ӵ�ǰ������������
* 
* 1.�ҵ���������С���󣩵�Ԫ������ף�β������
* 2.ѭ����һ��
* 
* ����
* ʱ�临�Ӷ� O(n^) ��ԶʱO(n^)��Ӧ�������������㷨�ѣ�
* �ռ临�Ӷ� O(1)
* �ȶ��� ���ȶ�
* �洢��ʽ��������������
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