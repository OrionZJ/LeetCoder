// 数学老师给小明出了一道等差数列求和的题目。但是粗心的小明忘记了一
// 部分的数列，只记得其中 N 个整数。
// 现在给出这 N 个整数，小明想知道包含这 N 个整数的最短的等差数列有
// 几项？

#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	vector<int> arr(n);
	vector<int> res;
	int minDis = INT_MAX;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	for (int i = 1; i < n; i++) {
		minDis = min(arr[i] - arr[i - 1], minDis);
	}
	for (int i = arr[0]; i <= arr.back(); i += minDis) {
		res.push_back(i);
	}
	cout << res.size();
	return 0;
}
