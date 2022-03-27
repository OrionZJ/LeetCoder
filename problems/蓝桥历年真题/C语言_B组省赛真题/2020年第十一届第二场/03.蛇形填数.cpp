// 如下图所示，小明用从1开始的正整数“蛇形”填充无限大的矩阵。
// 容易看出矩阵第二行第二列中的数是5。
// 请你计算矩阵中第20行第20列的数是多少？
// 1 2 6 7 15 …
// 3 5 8 14 …
// 4 9 13 …
// 10 12 …
// 11 …

#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int a = 20;
	int b = 2 * a - 1;
	int c = b + 0.5 *b * (b - 1);
	int d = (b - 1) + 0.5 *(b - 1) * (b - 2);
	int res = (c + d) / 2 + 1;
	cout << res; 
	return 0; 
}
