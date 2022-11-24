/* 
* �鲢���򣨷��η���
* 
* �ݹ��㷨��
* 1.�е�ֽ�
* 2.�ݹ�����������й鲢����
* 3.������������϶�Ϊһ �����ص�
* 
* �ǵݹ��㷨��
* 1.�����䳤��Ϊ1��ʼ�������л���Ϊ�����������������
* 2.���䳤�ȳɱ��������ϲ�����������
* 
* ����
* ʱ�临�Ӷȣ�O(nlogn) �����鲢�����ԭʼ���ݵ�����״̬�����У������������ϴ�ʱ�������ֳ�����ʱ����������
* �ռ临�Ӷȣ�O(n) �����鲢�������������к�ԭ���У�����Ҫ�������пռ�
* �ȶ��ԣ��ȶ������Ԫ�������λ�ò���
* �洢��ʽ�����������
*/

#include<iostream>
#include<vector>
using namespace std;

// �ݹ�
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

// �ǵݹ�
void merge_sort_2(vector<int> &nums) {
	// ���䳤����������ÿ�����䳤��Ϊi
	for (int i = 1; i <= nums.size(); i *= 2) {
		// �����������[j, j+i*2]
		int L_start = 0, L_end = 0;
		int R_start = 0, R_end = 0;
		for (L_start = 0; L_start < nums.size() - i; L_start = R_end) {
			// �����䣨����ҿ���
			L_end = L_start + i;
			// ������
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