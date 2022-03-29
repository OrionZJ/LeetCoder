// ����һ�ð��� N ���ڵ����ȫ��������
// ����ÿ���ڵ㶼��һ��Ȩֵ��
// ���� �ϵ��¡������ҵ�˳�������� A1, A2, �� �� �� AN������ͼ��ʾ:
// ����С��Ҫ����ͬ��ȵĽڵ��Ȩֵ����һ��
// ����֪���ĸ���ȵĽڵ�Ȩֵ֮�����?
// ����ж����ȵ�Ȩֵ��ͬΪ����������������С����ȡ�
// ע:��������� 1��

#include <bits/stdc++.h>
using namespace std;

int a2t(const vector<int> &a, int deep) {
	// 1 0, 2 1(2), 3 3(6), 4 7(14)
	
}

int main(void) {
	int n;
	cin >> n;
	vector<int> tree(n);
	vector<int> rootSum(1, 0);
	long long maxSum = 0;
	int ret = 0;
	for (int i = 0; i < n; i++) {
		cin >> tree[i];
	}
	int count = 0;
	for (int j = 1; j <= pow(2, j - 1); j++) {
		long long sum = 0;
		for (int tmp = count; count - tmp < j; count++) {
			sum += tree[count];
		}
		rootSum.push_back(sum);
		if (sum > maxSum) {
			maxSum = sum;
			ret = j;
		}
		if (count >= n - 1) {
			cout << ret;
			return 0;
		}
	}
	cout << ret;
	return 0;
}
