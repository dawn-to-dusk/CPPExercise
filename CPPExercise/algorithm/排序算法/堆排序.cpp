/*
* ������
* 1. �����ʼ���󶥶�
*  - �����һ����֧�ڵ㿪ʼɸѡ��i=n/2��Ϊ���һ����֧�ڵ㣬0�±겻ʹ�ã�
*  - ɸѡ���̣�ȷ����ǰ��֧�ڵ���������ӽڵ�����ӽڵ�i*2�����ӽڵ�i*2+1��,�������ɸѡ��ǰ��֧�ڵ�ĸ��ڵ�
* 2. �󶥶ѹ���ú���ڵ㼴Ϊ��ǰ���ڵ㣬ÿ�ε������ڵ������һ���ڵ��λ�ã������ֵ�ŵ���󣩣��õ�ȥ�����һ���ڵ����¶ѣ��ٴ�ɸѡ�󶥶�
* 
* ����
* ʱ�临�Ӷȣ�O(nlogn)
* �ռ临�Ӷȣ�O(1)
* �ȶ��ԣ����ȶ�
* �洢��ʽ�����飬������������±갴��������������˳��洢
* 
* ע�⣺�����򲻼�0λ�ã����Դ������漰�±�ĵط�����һ��
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

	// cur ��ǰɸѡ�ķ�֧�ڵ�
	// end ��ǰ�ѵ����һ���ڵ�
	void shift(vector<int>& nums, int cur, int end) {
		int cur_k = cur * 2; // cur������

		// cur�����ӣ��Ǹ�����ɸѡ�ķ�֧�ڵ�
		while (cur_k <= end) {
			// cur���Һ��� �� �Һ��ӽϴ�
			if (cur_k < end && nums[cur_k - 1] < nums[cur_k]) {
				cur_k++;
			}
			// ��ǰcur_kΪcur���Һ����еĽϴ���

			if (nums[cur-1] >= nums[cur_k-1]) {
				// cur���ڵ����cur��ɸѡ����
				break;
			}
			else {
				// cur_k��󣬽�����Ϊ���ڵ�
				swap(nums[cur-1], nums[cur_k-1]);
				// ����ɸcur_k��cur_k�Ǹոս�����ȥ�ģ���cur_kΪ���Ķ�δ�������Ǵ󶥶�
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


		// ��ʼ���󶥶�
		for (int i = n / 2; i > 0; i--) {
			shift(nums, i, n);
		}

		int end = n;
		while (end > 1) {
			// �����������һ��Ԫ��
			swap(nums[0], nums[end-1]);
			// �õ�ȥ�����һ��Ԫ�ص��¶�
			end--;
			// ���˸��ڵ�1���µģ�����������󶥶ѵģ�����ֻ��Ҫɸһ��1
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