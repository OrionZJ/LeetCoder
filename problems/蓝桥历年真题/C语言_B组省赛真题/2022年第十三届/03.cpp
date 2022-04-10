#include <bits/stdc++.h>
using namespace std;

int main(void) {
	long long a, b, n;
	cin >> a >> b >> n;
	long long cntD = 0;
	long long cntT = 0;
	while(1) {
		for (int i = 0; i < 5; i++) {
			if (cntT >= n) {
				cout << cntD;
				return 0;
			}
			cntT += a;
			cntD++;
		}
		for (int i = 0; i < 2; i++) {
			if (cntT >= n) {
				cout << cntD;
				return 0;
			}
			cntT += b;
			cntD++;
		}
	}
	return 0;
}
