/*
如【图1.jpg】, 有12张连在一起的12生肖的邮票。
现在你要从中剪下5张来，要求必须是连着的。
（仅仅连接一个角不算相连）
比如，【图2.jpg】，【图3.jpg】中，粉红色所示部分就是合格的剪取。

请你计算，一共有多少种不同的剪取方法。
*/ 

#include <bits/stdc++.h>
using namespace std;

void dfs(const vector<vector<int> > &rec, vector<vector<int> > &path, int r, int c, int &step) {
	if (step >= 5) return;
	if (rec[r][c] && !path[r][c]) {
		step++;
		path[r][c] = 1;
		if (r > 0) dfs(rec, path, r - 1, c, step);
		if (r < 2) dfs(rec, path, r + 1, c, step);
		if (c > 0) dfs(rec, path, r, c - 1, step);
		if (c < 3) dfs(rec, path, r, c + 1, step);
	}
}

bool jud(const vector<int> &table) {
	vector<vector<int> > rec(3, vector<int>(4, 0));
	int index = 0; 
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			if (table[index]) {
				rec[i][j] = 1;
			}
			index++;
		}
	}
	int step = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			if (rec[i][j]) {
				vector<vector<int> > path(3, vector<int>(4, 0));
				dfs(rec, path, i, j, step);
				if (step == 5)	return true;
				return false;
			}
			
		}
	}
	return false;
} 

int main(void) {
	vector<int> table = {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1};
	int cnt = 0;
	do {
		if (jud(table)) cnt++;
	} while (next_permutation(table.begin(), table.end()));
	cout << cnt;
	return 0;
}
