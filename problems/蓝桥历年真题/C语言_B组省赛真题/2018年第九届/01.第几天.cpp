// 2000年的1月1日，是那一年的第1天。
// 那么，2000年的5月4日，是那一年的第几天？
// 注意：需要提交的是一个整数，不要填写任何多余内容。

#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int data[] = {0, 31, 29, 31, 30, 31};
	int cnt = 0;
	for (int m = 1; m <=5; m++) {
		for (int d = 1; d <= data[m]; d++) {
			cnt++;
			if (m == 5 && d ==4) {
				cout << cnt;
				return 0;
			}
		}
	}
} 
