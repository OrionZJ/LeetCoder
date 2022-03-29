// 给定一棵包含 N 个节点的完全二叉树，
// 树上每个节点都有一个权值，
// 按从 上到下、从左到右的顺序依次是 A1, A2, · · · AN，如下图所示:
// 现在小明要把相同深度的节点的权值加在一起，
// 他想知道哪个深度的节点权值之和最大?
// 如果有多个深度的权值和同为最大，请你输出其中最小的深度。
// 注:根的深度是 1。

#include <bits/stdc++.h>
using namespace std;

int a2t(const vector<int> &a, int deep) {
	// 1 0, 2 1(2), 3 3(6), 4 7(14)
	
}

int main(void) {
	int n;
	cin >> n;
	vector<int> tree(n);
	vector<int> rootSum(1, 0);
	long long maxSum = 0;
	int ret = 0;
	for (int i = 0; i < n; i++) {
		cin >> tree[i];
	}
	int count = 0;
	for (int j = 1; j <= pow(2, j - 1); j++) {
		long long sum = 0;
		for (int tmp = count; count - tmp < j; count++) {
			sum += tree[count];
		}
		rootSum.push_back(sum);
		if (sum > maxSum) {
			maxSum = sum;
			ret = j;
		}
		if (count >= n - 1) {
			cout << ret;
			return 0;
		}
	}
	cout << ret;
	return 0;
}
