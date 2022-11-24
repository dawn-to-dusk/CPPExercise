/*
* ��������
* ���ƴ򶷵�����ÿ��ץһ���ƣ��Ӻ���ǰ�Ƚϣ�����ץ���Ʒŵ����ʴ�С��λ��
* 
* 1. ����һ��Ԫ�ص����������У�����Ϊ��������
* 2. ÿ�õ�һ���µ�Ԫ�أ����뵽��Ԫ�������������к��ʵ�λ��
* 
* ����
* ʱ�临�Ӷȣ�O(n^) ��õ����������O(n)
* �ռ临�Ӷȣ�O(1)
* �ȶ��ԣ��ȶ�
* �洢��ʽ���������������϶��һ��ѡ������
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