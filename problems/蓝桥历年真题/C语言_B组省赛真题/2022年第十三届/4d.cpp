#include <bits/stdc++.h>
using namespace std;

// 2 1 0 n=2    0 2 3

void grow(vector<long long> &tree) {
	for (int i = 0; i < tree.size(); i++){
		tree[i]++;
	}
}

int retMax(long long a, long long b, long long &cnt) {
	if (a < b) {  // »»ÁË 
		cnt = 0;
		return b;
	}
	else {
		cnt++;
		return a;
	}
}

int main(void) {
	int N;
	cin >> N;
	vector<long long> tree(N, 0);
	vector<long long> rec(N, 0);
	//while (1) {
		int cut = 0;
		long long swapT = 0;
		bool tRi = true;
		while (1) {
			grow(tree);
			rec[cut] = retMax(rec[cut], tree[cut], swapT);
			tree[cut] = 0;
			
			if (cut == N - 1) tRi = false;
			if (cut == 0) tRi = true;
			
			if (tRi) cut++;
			else cut--;
			if (swapT > 4 * N) break;
		}
	//}
	for (int i = 0; i < rec.size(); i++) {
		cout << rec[i] << '\n';
	}
	return 0;
}
