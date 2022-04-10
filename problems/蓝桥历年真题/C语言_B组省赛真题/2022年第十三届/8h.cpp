#include <bits/stdc++.h>
using namespace std;

long long rid(long long x, long long y, long long cx, long long cy) {
	return sqrt(pow(x - cx, 2) + pow(y - cy, 2));
}

int main(void) {
	int n, m;
	cin >> n >> m;
	vector<vector<long long> > lei(n, vector<long long>(3, 0));
	vector<vector<long long> > pai(m, vector<long long>(3, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> lei[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> pai[i][j];
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			lei[i][j];
		}
	}
}
