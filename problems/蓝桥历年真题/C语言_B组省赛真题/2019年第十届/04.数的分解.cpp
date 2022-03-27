// 把 2019分解成 3个各不相同的正整数之和，并且要求每个正整数都不包
// 含数字2和4，一共有多少种不同的分解方法？
// 注意交换 3个整数的顺序被视为同一种方法，例如 1000+1001+18和
// 1001+1000+18被视为同一种。

#include <bits/stdc++.h>
using namespace std;

bool judge(int num) {
	while (num) {
		if (num % 10 == 4 || num % 10 == 2) return true;
		num /= 10;
	}
	return false;
} 

int main(void) {
	int cnt = 0;
	for (int i = 1; i <= 2017; i++) {
		if (judge(i)) continue;
		for (int j = i + 1; j <= 2018; j++) {
			if (judge(j)) continue;
			for (int k = j + 1; k <= 2019; k++) {
				if (judge(k)) continue;
				if (i + j + k == 2019) cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}
