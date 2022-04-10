/* 
有N个瓶子，编号 1 ~ N，放在架子上。

比如有5个瓶子：
2 1 3 5 4

要求每次拿起2个瓶子，交换它们的位置。
经过若干次后，使得瓶子的序号为：
1 2 3 4 5

对于这么简单的情况，显然，至少需要交换2次就可以复位。

如果瓶子更多呢？你可以通过编程来解决。

输入格式为两行：
第一行: 一个正整数N（N<10000）, 表示瓶子的数目
第二行：N个正整数，用空格分开，表示瓶子目前的排列情况。
输出数据为一行一个正整数，表示至少交换多少次，才能完成排序。
*/

#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b) {
	a = a ^ b;
	b = b ^ a;
	a = a ^ b;
}


int main(void) {
	int N;
	cin >> N;
	vector<int> data(N);
	for (int i = 0; i < N; i++) {
		cin >> data[i];
	}
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		int minI = i;
		for (int j = i; j < N; j++) {
			if (data[j] < data[minI]) {
				minI = j;
			}
		}
		if (data[minI] != data[i]) {
			swap(data[minI], data[i]);
			cnt++;
		}
	}
	cout << cnt;
	return 0;
} 
