/*
如图p1.png所示的螺旋折线经过平面上所有整点恰好一次。
对于整点(X, Y)，我们定义它到原点的距离dis(X, Y)是从原点到(X, Y)的螺旋折线段的长度。
例如dis(0, 1)=3, dis(-2, -1)=9
给出整点坐标(X, Y)，你能计算出dis(X, Y)吗？
*/

#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int x, y;
	cin >> x >> y;
	int cor = max(abs(x), abs(y));
	int path = 0;
	int m = 1;
	//int n = 0;
	int ret = 0;
	vector<vector<int> > data(cor + 2, vector<int>(4, 0));
	while (m <= cor + 1) {
		path = 2 * m - 1 + path;
		data[m][0] = path;
		path = 2 * m - 1 + path;
		data[m][1] = path;
		path = 2 * m + path;
		data[m][2] = path;
		path = 2 * m + path;
		data[m][3] = path; 
		m++;
	}
	if (x >= 0 && y >= 0) {
		if (x <= y) ret = data[y][2] - (y - x);
		else ret = data[x][2] + (x - y);
	}
	else if (x >=0 && y < 0) {
		if (x < -y) ret = data[y][3] + (-y - x);
		else ret = data[x][3] - (x + y);
	}
	else if (x < 0 && y < 0) {
		if (-x >= -y + 1) ret = data[-x][0] + (-x + y - 1);
		else ret = data[-y + 1][0] - (-y + 1 + x);
	} 
	else {
		if (-x >= y) ret = data[-x][1] - (-x - y);
		else ret = data[y][1] + (y + x);
	}
	cout << ret;
	return 0;
}
