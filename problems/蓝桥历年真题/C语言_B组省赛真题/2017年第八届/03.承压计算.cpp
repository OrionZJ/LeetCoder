/*
X星球的高科技实验室中整齐地堆放着某批珍贵金属原料。
每块金属原料的外形、尺寸完全一致，但重量不同。
金属材料被严格地堆放成金字塔形。

 5 9 4 5 5 7 5 5 6 3 5 3 9 5 8 9 5 4 1 2 6 1 4 3 5 3 2 4 1
X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X
012345678901234567890123456789012345678901234567890123456789
*/

#include <bits/stdc++.h>
using namespace std;

int main(void) {
	vector<vector<long double> > data(30, vector<long double>(59, 0));
	for (int row = 0; row < 30; row++) {
		int cnt = 0;
		for (int col = 59 / 2 - row; cnt < row + 1; col += 2) {
			if (row < 29) cin >> data[row][col];
			if (row > 0) {
				if (col > 0) data[row][col] += (data[row - 1][col - 1] / 2);
				if (col < 58) data[row][col] += (data[row - 1][col + 1] / 2);
			}
			cnt++;
		}
	} 
	/*
	long double minD = 999;
	long double maxD = 0;
	for (int i = 0; i < 59; i += 2) {
		cout << data[29][i] << ' ';
		minD = min(data[29][i], minD);
		maxD = max(data[29][i], maxD);
	}
	cout << "\n" << minD << ' ' << maxD << endl;
	cout << 2086458231 / minD * maxD;
	*/
	
	for (int i = 0; i < data.size(); i++) {
		for (int j = 0; j < data.back().size(); j++) {
			if (data[i][j] == 0) cout << ' ';
			else cout << data[i][j];
		}
		cout << "\n";
	}
	
	system("pause");
	return 0;
}
