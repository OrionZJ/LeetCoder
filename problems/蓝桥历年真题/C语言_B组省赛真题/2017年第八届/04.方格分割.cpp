/*
6x6的方格，沿着格子的边线剪开成两部分。
要求这两部分的形状完全相同。
*/

#include <bits/stdc++.h>
using namespace std;

void backTracking(vector<vector<bool> > &data, int x, int y, int &cnt) {
	if (x == 0 || x == 6 || y == 0 || y == 6) {
		cnt++;
		return;
	}
	if (data[x][y] == true) return;
	data[x][y] = true;
	data[6 - x][6 - y] = true; 
	backTracking(data, x + 1, y, cnt);
	backTracking(data, x, y + 1, cnt);
	backTracking(data, x - 1, y, cnt);
	backTracking(data, x, y - 1, cnt);
	data[6 - x][6 - y] = false;
	data[x][y] = false;
}

int main(void) {
	vector<vector<bool> > data(7, vector<bool>(7, false));
	int cnt = 0;
	backTracking(data, 3, 3, cnt);
	cout << cnt / 4;
	return 0;
}

 
