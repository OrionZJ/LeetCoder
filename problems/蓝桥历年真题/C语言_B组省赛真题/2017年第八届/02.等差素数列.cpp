/*
2,3,5,7,11,13,�����������С�
���ƣ�7,37,67,97,127,157 ������ȫ��������ɵĵȲ����У��еȲ��������С�
�ϱߵ����й���Ϊ30������Ϊ6��
2004�꣬�����뻪������������֤���ˣ��������ⳤ�ȵ������Ȳ����С�
������������һ��˵ĳɹ���
����һ����Ϊ����������������еļ�������������ĵ�������
����Ϊ10�ĵȲ������У��乫����Сֵ�Ƕ��٣�
*/

#include <bits/stdc++.h>
using namespace std;

bool judge(int n) {
	if (n == 2) return true;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) return false;
	}
	return true;
}

int main(void) {
	int beg = 2;

	vector<int> a(10, 0);
	for (int i = beg; ;i++) {
		for (int d = 1; d < 1000; d++) {
			for (int cnt = 0; cnt < 10; cnt++) {
				if (cnt > 0) a[cnt] = a[cnt - 1] + d;
				else a[cnt] = i;
				if (!judge(a[cnt])) break;
				else {
					if (cnt >= 9) {
						cout << d;
						return 0;
					}
				} 
			}
		}
	}
} 

