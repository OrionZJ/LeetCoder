/*
四平方和定理，又称为拉格朗日定理：
每个正整数都可以表示为至多4个正整数的平方和。
如果把0包括进去，就正好可以表示为4个数的平方和。比如：
5 = 0^2 + 0^2 + 1^2 + 2^2
7 = 1^2 + 1^2 + 1^2 + 2^2
（^符号表示乘方的意思）
对于一个给定的正整数，可能存在多种平方和的表示法。
要求你对4个数排序：
0 <= a <= b <= c <= d
并对所有的可能表示法按 a,b,c,d 为联合主键升序排列，最后输出第一个表示法
程序输入为一个正整数N (N<5000000)
要求输出4个非负整数，按从小到大排序，中间用空格分开
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
