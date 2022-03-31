/*
����������������
A = [A1, A2, �� AN],
B = [B1, B2, �� BN],
C = [C1, C2, �� CN]��
����ͳ���ж��ٸ���Ԫ��(i, j, k) ���㣺

1 <= i, j, k <= N
Ai < Bj < Ck
�������ʽ��
��һ�а���һ������N��
�ڶ��а���N������A1, A2, �� AN��
�����а���N������B1, B2, �� BN��
�����а���N������C1, C2, �� CN��

����30%�����ݣ�1 <= N <= 100
����60%�����ݣ�1 <= N <= 1000
����100%�����ݣ�1 <= N <= 100000 0 <= Ai, Bi, Ci <= 100000
*/

#include <bits/stdc++.h>
using namespace std;

void culRef(const vector<int> &a, const vector<int> &b, vector<int> &ar) {
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b.size(); j++) {
			if (a[i] < b[j]) {
				ar[i] = j;
				break;
			}
		}
	}
}

int main(void) {
	int n;
	cin >> n;
	vector<int> a(n), b(n), c(n);
	int ret = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	sort(c.begin(), c.end());
	vector<int> ar(n, -1), br(n, -1);
	culRef(a, b, ar);
	culRef(b, c, br);
	for (int i = 0; i < n; i++) {
		if (ar[i] == -1) continue;
		for (int j = ar[i]; j < n; j++) {
			if (br[j] == -1) continue;
			ret += (n - br[j]);
		}
	}
	cout << ret;
	return 0;
}
