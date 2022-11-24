/*
* �������򣨷��η���
* 1. ȷ���ֽ��i����߽硢�ұ߽硢�е�
* 2. �����������䣬ʹ��������������ֵС��i��������������ֵ����i �����ص�
* 3. �ݹ鴦������������ 
* 
* ����
* ʱ�临�Ӷȣ�O(nlogn)-O(n^) ���������������п�������ʱ�����ܽϺã��������������У���������������������
* �ռ临�Ӷȣ�O(logn) ���� ��Ҫһ��ջ�����ÿһ��ݹ���õı�Ҫ��Ϣ���ݹ���Զ�������ǳ����ռ䣩
* �ȶ��ԣ����ȶ����������Ԫ���������λ�ÿ��ܷ����仯��
* �洢��ʽ�����飬˳��洢����ѯ�϶ࣩ
* ����ÿһ����ȷ����Ŧ������λ��
*/

#include<iostream>
#include<vector>
using namespace std;

void swap(vector<int> &nums, int i, int j) {
	int tmp = nums[i];
	nums[i] = nums[j];
	nums[j] = tmp;
}

void quick_sort(vector<int> &nums, int l, int r) {
	if (l >= r) {
		return;
	}
	int x = (l + r) >> 1;
	//int x = l;
	int Vx = nums[x];
	// ������ע��ȡ�߽�����ֵ����Ϊdo whileÿ�λ�����һ��++/--
	// �������do while��ѭ��ʱ��i��j��value���ʱָ���޷��ƶ�
	int i = l - 1, j = r + 1;
	while (i < j) {
		do i++;
		while (nums[i] < Vx);
		do j--;  
		while (nums[j] > Vx);
		if (i < j) {
			swap(nums, i, j);
		}
	}
	quick_sort(nums, l, j);
	quick_sort(nums, j + 1, r);
	// ������ע��߽�ֵ
	// ����߽�ֵΪl����(l + r) >> 1������ʹ��i-1��i�����ܳ�����ѭ��
	// ����߽�ֵΪr����(l + r + 1) >> 1������ʹ��j��j+1�����ܳ�����ѭ��
	// ��ѭ��ָ[0,1]����������һֱ��[0,-1]������һֱ��[0,1]����
}

int main() {
	int n;
	cin >> n;

	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	quick_sort(nums, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << nums[i] << " ";
	}

	return 0;
}