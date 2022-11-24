/*
* �������򣨷ǱȽ��������㷨��
* ǰ�᣺������������ȷ����Χ������
* 1. ȷ�����ݷ�Χ����С���ֵ��
* 2. ͳ��������ֵΪi�����ĸ���ni����Ϊ��������ĵ�i���ֵ
* 3. ����������ǰ�ۼӣ�����ֵC[2] = C[2] + C[1]������ȷ��ֵ2���ֵ�λ��
* 4. ����������飬Ԫ��i���������C[i]�ÿȡ��һ��Ԫ�أ�C[i]��1
* 
* ����
* ʱ�临�Ӷȣ�O(n+k)
* �ռ临�Ӷȣ�O(k)
* �ȶ��ԣ��ȶ�
* �洢��ʽ��������������������洢
* �ʺ����ݷ�Χ���������
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