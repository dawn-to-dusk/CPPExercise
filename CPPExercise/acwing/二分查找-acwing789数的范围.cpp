/*
* ���ֲ��ң��������֣�
* һ���ǲ��ҷ���ĳһ�����ԣ��Ǳ�Ҫ���������е�ĳ��ֵ
* 1. ȡ�е�mid = (l + r) >> 1
* 2. ����check(mid)�ж�Ԫ���������ĸ����䣬������l/r����
* 3. l==rʱȡ�����
* 
* ע�⣺
* 1. mid���㷽ʽ���������������l=midʱ��mid = (l + r + 1) >> 1���������һ�����ܳ���l��mid��ȣ���ôl=mid���������Ч
* 2. ȡ���������ʱ��������������ѭ��ʱ����l>r����ôֱ����������ȡֵ���ܻ��������Ϊmid����ȡ�����б߽�ֵ����һ���һ���±�������
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	void solve(vector<int> nums, vector<int> query) {
		for (int i = 0; i < query.size(); i++) {
			int s = getStart(nums, query[i]);
			int e = -1;
			if (s != -1) {
				e = getEnd(nums, query[i]);
			}
			cout << s << " " << e << endl;
		}
	}

	// ��ȡ��ʼλ��
	int getStart(vector<int> nums, int val) {
		int left = 0;
		int right = nums.size() - 1;
		while (left < right) {
			int mid = (left + right) >> 1;
			if (nums[mid] == val) {
				right = mid;
			}
			else if (nums[mid] > val) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		if (left > right || nums[left] != val) {
			return -1;
		}
		else {
			return left;
		}
	}
	// ��ȡ��ֹλ��
	int getEnd(vector<int> nums, int val) {
		int left = 0;
		int right = nums.size() - 1;
		while (left < right) {
			// ������ע��˴���Ҫ��һ
			// �������һ�����ܳ���left==mid==left��if��true��֧��Ч������ѭ��
			int mid = (left + right + 1) >> 1;
			if (nums[mid] == val) {
				left = mid;
			}
			else if (nums[mid] > val) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		if (left > right || nums[left] != val) {
			return -1;
		}
		else {
			return left;
		}
	}
};

int main() {
	int n, q;
	cin >> n >> q;
	// ��������
	vector<int> nums(n);
	// ��ѯ
	vector<int> query(q);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	for (int i = 0; i < q; i++) {
		cin >> query[i];
	}

	// ��ѯÿ����ѯԪ�ص���ʼλ������ֹλ��
	Solution().solve(nums, query);

	return 0;
}