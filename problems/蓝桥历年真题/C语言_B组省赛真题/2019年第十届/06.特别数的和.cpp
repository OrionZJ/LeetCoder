// С������λ�к��� 2��0��1��9 �����ֺܸ���Ȥ��������ǰ�� 0�� ���� 1 ��
// 40 �������������� 1��2��9��10 �� 32��39 �� 40���� 28 �������ǵĺ��� 574��
// ���ʣ��� 1 �� n �У��������������ĺ��Ƕ��٣�

#include <bits/stdc++.h>
using namespace std;

bool judge(int num) {
	while (num) {
		int tmp = num % 10;
		if (tmp == 2 || tmp == 0 || tmp == 1 || tmp == 9) {
			return true;
		}
		num /= 10;
	}	
	return false;
}

int main(void) {
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		if (judge(i)) sum += i;
	}
	cout << sum;
	return 0;
}
