/*
     B      DEF
A + --- + ------- = 10
     C      GHI

这个算式中A到I代表1到9的数字，不同的字母代表不同的数字。
比如：
6+8/3+952/714 就是一种解法，
5+3/1+972/486 是另一种解法。
这个算式一共有多少种解法？
*/

#include <bits/stdc++.h>
using namespace std;

int main(void) {
	vector<float> can(9);
	int cnt = 0;
	for (int i = 1; i <= 9; i++) {
		can[i - 1] = i;
	}
	do {
		float res = can[0] + (can[1] / can[2]) + ((can[3]*100 + can[4]*10 + can[5]) / (can[6]*100 + can[7]*10 + can[8]));
		if (fabs(10 - res) <= 1e-6) cnt++;
	} while (next_permutation(can.begin(), can.end()));
	cout << cnt;
	return 0;
}
