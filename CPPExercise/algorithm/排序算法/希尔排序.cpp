/*
* ϣ�����򣨲�������Ľ������ڲ���ֱ�Ӳ�������
* 1.�����а�һ���������飬����ÿһ����в�������
* 2.�����𽥼�СΪ1�����վ�ֻʣ��һ�飬�������һ�ֲ�������
* 
* ����
* ʱ�临�Ӷȣ�O(nlogn)���O(n^)
* �ռ临�Ӷȣ�O(1)
* �ȶ��ԣ����ȶ�
* �洢��ʽ�����飬�����ǰ��±�˳���
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
		// xΪ�����������ɱ���С��1
		for (int  x = nums.size() /2; x > 0; x /= 2) {
			// ��������Ϊx��ÿ������Ĳ������򣬴��±�x��ʼ�ķ��鿪ʼ���൱�ڲ���������±�1��ʼ��ǰ��λ�ã�
			for (int i = x; i < nums.size(); i++) {
				// �±�i���ڷ����һ�˲���
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