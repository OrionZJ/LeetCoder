 #include <bits/stdc++.h>
 using namespace std;
 
 bool judge(int m, int d) {
 	vector<int> s = {2,0,0,0,0};
 	s[1] = m / 10;
 	s[2] = m % 10;
 	s[3] = d / 10;
 	s[4] = d % 10;
 	int cnt = 0;
 	bool fir = false;
 	for (int i = 2; i < 5; i++) {
 		if (s[i] - s[i-1] == 1) {
 			cnt++;
 			if (i == 2) fir = true;
 			if (cnt == 2) return true;
 		}
 		if (fir && s[i] - s[i-1] != 1) {
 			cnt = 0;
 		}
 	}
 	return false;
 }
 
 int main(void) {
 	vector<int> pin = {0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
 	vector<int> run = {0,31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
 	int cnt = 0;
 	for (int m = 1; m <= 12; m++) {
 		for (int d = 1; d <= pin[m]; d++) {
 			if (judge(m, d)) {
 				cnt++;
 			}
 		}
 	}
 	cout << cnt;
 	return 0;
 }
