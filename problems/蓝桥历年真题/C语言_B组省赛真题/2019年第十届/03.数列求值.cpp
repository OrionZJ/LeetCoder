// 给定数列1,1,1,3,5,9,17,…，
// 从第4项开始，每项都是前3项的和。求
// 第20190324项的最后4位数字。

#include <bits/stdc++.h>
using namespace std;

int main(void) {
	vector<int> data(20190324, 0);
	data[0] = 1;
	data[1] = 1;
	data[2] = 1;
	for (int i = 3; i < 20190324; i++) {
		data[i] = (data[i - 3] + data[i - 2] + data[i - 1]) % 10000;
	}
	cout << data[20190323];
	return 0;
}
