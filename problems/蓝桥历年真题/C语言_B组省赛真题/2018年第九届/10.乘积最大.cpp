/*
����N������A1, A2, �� AN���������ѡ��K������ʹ��˻����

����������ĳ˻������ڳ˻����ܳ������ͷ�Χ����ֻ������˻�����1000000009��������

ע�⣬���X<0�� ���Ƕ���X����1000000009�������Ǹ�(-X)����1000000009�������� ����0-((0-x) %
1000000009)
*/

#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int n, k;
	cin >> n >> k;
	vector<long long> data(n);
	long long ans = 1;
	for (int i = 0; i < n; i++) {
		cin >> data[i];
	}
	sort(data.begin(), data.end());
	while (k) {
		if (k % 2 == 0) {
			if (data[0] * data[1] > data[data.size() - 2] * data[data.size() - 1]) {
				ans = (ans * data[0] * data[1]) % 1000000009;
				data.erase(data.begin(), data.begin() + 1);
			} else {
				ans = (ans * data[data.size() - 2] * data[data.size() - 1]) % 1000000009;
				data.pop_back();
				data.pop_back();
			}
			k -= 2;
		} else {
			ans = ans * data.back() % 1000000009;
			data.pop_back();
			k--;
		}
	}
	cout << ans;
	return 0;
}
