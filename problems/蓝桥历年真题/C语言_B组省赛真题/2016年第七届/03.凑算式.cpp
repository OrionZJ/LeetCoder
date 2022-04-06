/*
     B      DEF
A + --- + ------- = 10
     C      GHI

�����ʽ��A��I����1��9�����֣���ͬ����ĸ����ͬ�����֡�
���磺
6+8/3+952/714 ����һ�ֽⷨ��
5+3/1+972/486 ����һ�ֽⷨ��
�����ʽһ���ж����ֽⷨ��
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
