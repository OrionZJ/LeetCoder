// 给定 N 个加号、M 个减号以及 N + M + 1 个整数 A 1 ,A 2 ,··· ,A N+M+1 ，小
// 明想知道在所有由这 N 个加号、M 个减号以及 N + M +1 个整数凑出的合法的
// 后缀表达式中，结果最大的是哪一个？
// 请你输出这个最大的结果。
// 例如使用1 2 3 + -，则 “2 3 + 1 -” 这个后缀表达式结果是 4，是最大的。
// 输入格式:
// 第一行包含两个整数 N 和 M。
// 第二行包含 N + M + 1 个整数 A 1 ,A 2 ,··· ,A N+M+1 。
// 输出格式:
// 输出一个整数，代表答案。

#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int n, m;
	cin >> n >> m;
	vector<int> arr(n + m + 1);
	int sum = 0; 
	for (int i = 0; i < arr.size(); i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	int minPos = -1;
	int maxNeg = -1;
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] < 0) {
			maxNeg = i;
		} 
		else if (arr[i] > 0) {
			minPos = i;
			break;
		}
	}
	if (maxNeg == arr.size() - 1) {  // 全负 
		for (int i = 0; i < maxNeg; i++) {
			sum -= arr[i];
		} 
		sum += maxNeg;
	} 
	else if (minPos == 0) {  // 全正
		sum -= arr[minPos];
		for (int i = 1; i < arr.size(); i++) {
			sum += arr[i];
		} 
	}
	else {  // 有正有负
		int minAbs = INT_MAX;
		for (int i = 0; i < arr.size(); i++) {
			arr[i] = abs(arr[i]);
			sum += arr[i];
			if (arr[i] < minAbs) minAbs = arr[i];
		} 
		sum -= 2 * minAbs;
	}
	cout << sum;
	return 0;
}
// 2 2
// -2 -1 0 2 3
// 0 -2 - -1 - 2 3 + +