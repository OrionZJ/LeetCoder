/* 
��N��ƿ�ӣ���� 1 ~ N�����ڼ����ϡ�

������5��ƿ�ӣ�
2 1 3 5 4

Ҫ��ÿ������2��ƿ�ӣ��������ǵ�λ�á�
�������ɴκ�ʹ��ƿ�ӵ����Ϊ��
1 2 3 4 5

������ô�򵥵��������Ȼ��������Ҫ����2�ξͿ��Ը�λ��

���ƿ�Ӹ����أ������ͨ������������

�����ʽΪ���У�
��һ��: һ��������N��N<10000��, ��ʾƿ�ӵ���Ŀ
�ڶ��У�N�����������ÿո�ֿ�����ʾƿ��Ŀǰ�����������
�������Ϊһ��һ������������ʾ���ٽ������ٴΣ������������
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
