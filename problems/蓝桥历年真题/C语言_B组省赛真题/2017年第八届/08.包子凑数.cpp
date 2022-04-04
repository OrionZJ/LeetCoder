/*
小明几乎每天早晨都会在一家包子铺吃早餐。他发现这家包子铺有N种蒸笼，其中第i种蒸笼恰好能放Ai个包子。
每种蒸笼都有非常多笼，可以认为是无限笼。
每当有顾客想买X个包子，卖包子的大叔就会迅速选出若干笼包子来，使得这若干笼中恰好一共有X个包子。
比如一共有3种蒸笼，分别能放3、4和5个包子。
当顾客想买11个包子时，大叔就会选2笼3个的再加1笼5个的（也可能选出1笼3个的再加2笼4个的）。
当然有时包子大叔无论如何也凑不出顾客想买的数量。比如一共有3种蒸笼，分别能放4、5和6个包子。
而顾客想买7个包子时，大叔就凑不出来了。
小明想知道一共有多少种数目是包子大叔凑不出来的。

输入
第一行包含一个整数N。(1 <= N <= 100)
以下N行每行包含一个整数Ai。(1 <= Ai <= 100)

输出

一个整数代表答案。如果凑不出的数目有无限多个，输出INF。
*/

#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	gcd(b, a % b);
}

int main(void) {
	int N;
	cin >> N;
	vector<int> data(N);
	for (int i = 0; i < N; i++) {
		cin >> data[i];
	}
	int x = data[0];
	for (int i = 1; i < N; i++) x = gcd(x, data[i]);
	if (x > 1) {
		cout << "INF\n";
		return 0;
	}
	
	vector<vector<bool> > dp(N, vector<bool>(10001, false));
	dp[0][0] = true;
	for (int j = 0; j < 10001; j++) {
		if (j % data[0] == 0) dp[0][j] = true;
	}
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < 10001; j++) {
			if (dp[i - 1][j]) dp[i][j] = true;
			int k = 1;
			while (j - k * data[i] >= 0) {
				if (dp[i - 1][j - k * data[i]]) {
					dp[i][j] = true;
					break;
				}
				k++;
			}
		}
	}
	int cnt = 0;
	for (int i = 1; i < 10001; i++) {
		if (dp[N - 1][i] == false) cnt++;
	}
	cout << cnt;
	return 0;
} 
