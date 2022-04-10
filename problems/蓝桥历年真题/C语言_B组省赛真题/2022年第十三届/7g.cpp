#include <bits/stdc++.h>
using namespace std;

/*
	····· ·· 
	·····   · 
	dp[n]：长度为n的画布有dp[n]种方式拼满 
*/

int main(void) {
	long long N;
	cin >> N;
	vector<long long> dp(N + 1, 0);
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i < dp.size(); i++) {
		dp[i] = dp[i - 1] * 1 + dp[i - 2] * 1;
		dp[i] += (dp[i - 3] * 2);
		if (i >= 4) dp[i] += (dp[i - 4] * 2);
		dp[i] %=  1000000007;
	}
	cout << dp.back();
	return 0;
} 
