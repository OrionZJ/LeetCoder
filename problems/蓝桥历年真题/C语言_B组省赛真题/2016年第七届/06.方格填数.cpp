/*
如下的10个格子
（如果显示有问题，也可以参看【图1.jpg】）
填入0~9的数字。要求：连续的两个数字不能相邻。
（左右、上下、对角都算相邻）
一共有多少种可能的填数方案？
请填写表示方案数目的整数。
注意：你提交的应该是一个整数，不要填写任何多余的内容或说明性文字。
*/

#include <bits/stdc++.h>
using namespace std;

bool judge(int row, int col,const vector<vector<int> > &pic) {
	if (row > 0) {
		if(abs(pic[row - 1][col] - pic[row][col]) == 1) return false;
	}
	if (row < 2) {
		if(abs(pic[row + 1][col] - pic[row][col]) == 1) return false;
	}
	if (col > 0) {
		if(abs(pic[row][col - 1] - pic[row][col]) == 1) return false;
	}
	if (col < 3) {
		if(abs(pic[row][col + 1] - pic[row][col]) == 1) return false;
	}
	if (row > 0 && col > 0) {
		if(abs(pic[row - 1][col - 1] - pic[row][col]) == 1) return false;
	}
	if (row < 2 && col < 3) {
		if(abs(pic[row + 1][col + 1] - pic[row][col]) == 1) return false;
	}
	if (row > 0 && col < 3) {
		if(abs(pic[row - 1][col + 1] - pic[row][col]) == 1) return false;
	}
	if (row < 2 && col > 0) {
		if(abs(pic[row + 1][col - 1] - pic[row][col]) == 1) return false;
	}
	return true;
}

int main(void) {
	vector<int> can(10);
	for (int i = 0; i <= 9; i++) can[i] = i;
	vector<vector<int> > pic(3, vector<int>(4, INT_MAX));
	int cnt = 0;
	do {
		int pos = 0;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 4; j++) {
				if (i == 0 && j == 0) continue;
				if (i == 2 && j == 3) continue;
				pic[i][j] = can[pos++];
			}
		}
		bool jud = true;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 4; j++) {
				if (i == 0 && j == 0) continue;
				if (i == 2 && j == 3) continue;
				if (!judge(i, j, pic)) {
					jud = false;
					break;
				}
			}
		}
		if (jud) cnt++;		
	} while(next_permutation(can.begin(), can.end()));
	cout << cnt;
	return 0;
} 
