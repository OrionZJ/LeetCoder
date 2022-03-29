// 小明对数位中含有 2、0、1、9 的数字很感兴趣（不包括前导 0） ，在 1 到
// 40 中这样的数包括 1、2、9、10 至 32、39 和 40，共 28 个，他们的和是 574。
// 请问，在 1 到 n 中，所有这样的数的和是多少？

#include <bits/stdc++.h>
using namespace std;

bool judge(int num) {
	while (num) {
		int tmp = num % 10;
		if (tmp == 2 || tmp == 0 || tmp == 1 || tmp == 9) {
			return true;
		}
		num /= 10;
	}	
	return false;
}

int main(void) {
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		if (judge(i)) sum += i;
	}
	cout << sum;
	return 0;
}
