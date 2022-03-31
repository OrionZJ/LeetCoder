/*
给定三个整数数组
A = [A1, A2, … AN],
B = [B1, B2, … BN],
C = [C1, C2, … CN]，
请你统计有多少个三元组(i, j, k) 满足：

1 <= i, j, k <= N
Ai < Bj < Ck
【输入格式】
第一行包含一个整数N。
第二行包含N个整数A1, A2, … AN。
第三行包含N个整数B1, B2, … BN。
第四行包含N个整数C1, C2, … CN。

对于30%的数据，1 <= N <= 100
对于60%的数据，1 <= N <= 1000
对于100%的数据，1 <= N <= 100000 0 <= Ai, Bi, Ci <= 100000
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
