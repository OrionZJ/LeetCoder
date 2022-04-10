#include <bits/stdc++.h>
using namespace std;

long long sumMI(int lx, int ly, int rx, int ry, const vector<vector<int> > &data) {
	long long sum = 0;
	for (int i = lx; i <= rx; i++) {
		for (int j = ly; j <= ry; j++) {
			sum += data[i][j];
		}
	}
	return sum;
}

void initMI(vector<vector<int> > &data) {
	for (int i = 0; i < data.size(); i++) {
		for (int j = 0; j < data[i].size(); j++) {
			cin >> data[i][j];
		}
	}
}

int main(void) {
	int N, M;
	long long K;
	cin >> N >> M >> K;
	vector<vector<int> > data(N, vector<int>(M, 0));
	initMI(data);
	int cnt = 0;
	for (int lx = 0; lx < data.size(); lx++) {
		for (int ly = 0; ly < data[lx].size(); ly++) {
			for (int rx = lx; rx < data.size(); rx++) {
				for (int ry = ly; ry < data[rx].size(); ry++) {
					long long su = sumMI(lx, ly, rx, ry, data);
					if (su <= K) cnt++;
				}
			}
		}
	}
	cout << cnt;
	return 0;
} 
