#include <bits/stdc++.h>
using namespace std;

/*

*/

void backTracking(int dou, int n, int m, int N, int M, bool dian, long long &cnt) {
	if (n >= N && m >= M) {
		//cnt++;
		return;
	}
	if (dian) {
		if (n >= N) return;
		dou *= 2;
		n++;
	}
	else if (!dian) {
		if (m >= M) return; 
		if (dou == 0) return;
		dou--;
		m++;
		if (n == N && m == M && dou == 0) {
			cnt++;
			cnt %= 1000000007;
		}
	}
	
	backTracking(dou, n, m, N, M, true, cnt);
	backTracking(dou, n, m, N, M, false, cnt);
	
} 

int main(void) {
	int N, M;
	cin >> N >> M;
	long long cnt = 0;
	long long dou = 2;
	backTracking(dou, 0, 0, N, M, true, cnt);
	backTracking(dou, 0, 0, N, M, false, cnt);
	cout << cnt;
	return 0;
}
