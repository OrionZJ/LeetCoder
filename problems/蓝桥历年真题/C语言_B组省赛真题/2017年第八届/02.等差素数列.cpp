/*
2,3,5,7,11,13,…是素数序列。
类似：7,37,67,97,127,157 这样完全由素数组成的等差数列，叫等差素数数列。
上边的数列公差为30，长度为6。
2004年，格林与华人陶哲轩合作证明了：存在任意长度的素数等差数列。
这是数论领域一项惊人的成果！
有这一理论为基础，请你借助手中的计算机，满怀信心地搜索：
长度为10的等差素数列，其公差最小值是多少？
*/

#include <bits/stdc++.h>
using namespace std;

bool judge(int n) {
	if (n == 2) return true;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) return false;
	}
	return true;
}

int main(void) {
	int beg = 2;

	vector<int> a(10, 0);
	for (int i = beg; ;i++) {
		for (int d = 1; d < 1000; d++) {
			for (int cnt = 0; cnt < 10; cnt++) {
				if (cnt > 0) a[cnt] = a[cnt - 1] + d;
				else a[cnt] = i;
				if (!judge(a[cnt])) break;
				else {
					if (cnt >= 9) {
						cout << d;
						return 0;
					}
				} 
			}
		}
	}
} 

