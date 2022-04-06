/*
���µ�10������
�������ʾ�����⣬Ҳ���Բο���ͼ1.jpg����
����0~9�����֡�Ҫ���������������ֲ������ڡ�
�����ҡ����¡��ԽǶ������ڣ�
һ���ж����ֿ��ܵ�����������
����д��ʾ������Ŀ��������
ע�⣺���ύ��Ӧ����һ����������Ҫ��д�κζ�������ݻ�˵�������֡�
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
