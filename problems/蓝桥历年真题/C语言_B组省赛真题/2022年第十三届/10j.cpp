#include <bits/stdc++.h>
using namespace std;

long long cul(long long num) {
	return sqrt(num / 2 + 1);
}

void cut(vector<long long> &data, long long &cnt) {
	int maxInd = 0;
	//int count = 0;
	for (int i = 0; i < data.size(); i++) {
		if (data[i] > data[maxInd]) {
			maxInd = i;
		}
	}
	
	if (data[maxInd] == 1) return;
	
	long long tmp = data[maxInd];
	for (int i = maxInd; i < data.size(); i++) {
		if (data[i] != tmp) break;
		data[i] = cul(data[i]);
	}
	cnt++;
/*	
	for (int i = 0; i < data.size(); i++) {
		cout << data[i] << ' ';
	}
	cout << '\n';
*/	
	cut(data, cnt);
}

int main(void) {
	long long n;
	cin >> n;
	vector<long long> data(n, 0);
	for (int i = 0; i < data.size(); i++) {
		cin >> data[i];
	}
	long long cnt = 0;
	cut(data, cnt);
	cout << cnt;
	return 0;	
}
