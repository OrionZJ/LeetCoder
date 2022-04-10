/*
��ƽ���Ͷ����ֳ�Ϊ�������ն���
ÿ�������������Ա�ʾΪ����4����������ƽ���͡�
�����0������ȥ�������ÿ��Ա�ʾΪ4������ƽ���͡����磺
5 = 0^2 + 0^2 + 1^2 + 2^2
7 = 1^2 + 1^2 + 1^2 + 2^2
��^���ű�ʾ�˷�����˼��
����һ�������������������ܴ��ڶ���ƽ���͵ı�ʾ����
Ҫ�����4��������
0 <= a <= b <= c <= d
�������еĿ��ܱ�ʾ���� a,b,c,d Ϊ���������������У���������һ����ʾ��
��������Ϊһ��������N (N<5000000)
Ҫ�����4���Ǹ�����������С���������м��ÿո�ֿ�
*/

#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int N;
	cin >> N;
	for (int i = 0; i <= sqrt(N); i++) {
		int remain1 = N - i*i;
		for (int j = i; j <= sqrt(remain1); j++) {
			int remain2 = remain1 - j*j;
			for (int m = j; m <= sqrt(remain2); m++) {
				int remain3 = remain2 - m*m;
				for (int n = m; n <= sqrt(remain3); n++) {
					if (i*i + j*j + m*m + n*n == N) {
						cout << i << ' ' << j << ' ' << m << ' ' << n;
						return 0;
					}
				}
			}
		}
	}
	return 0;
}
