// ��ѧ��ʦ��С������һ���Ȳ�������͵���Ŀ�����Ǵ��ĵ�С��������һ
// ���ֵ����У�ֻ�ǵ����� N ��������
// ���ڸ����� N ��������С����֪�������� N ����������̵ĵȲ�������
// ���

#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	vector<int> arr(n);
	vector<int> res;
	int minDis = INT_MAX;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	for (int i = 1; i < n; i++) {
		minDis = min(arr[i] - arr[i - 1], minDis);
	}
	for (int i = arr[0]; i <= arr.back(); i += minDis) {
		res.push_back(i);
	}
	cout << res.size();
	return 0;
}
