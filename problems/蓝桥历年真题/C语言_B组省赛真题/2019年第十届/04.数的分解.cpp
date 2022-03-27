// �� 2019�ֽ�� 3��������ͬ��������֮�ͣ�����Ҫ��ÿ��������������
// ������2��4��һ���ж����ֲ�ͬ�ķֽⷽ����
// ע�⽻�� 3��������˳����Ϊͬһ�ַ��������� 1000+1001+18��
// 1001+1000+18����Ϊͬһ�֡�

#include <bits/stdc++.h>
using namespace std;

bool judge(int num) {
	while (num) {
		if (num % 10 == 4 || num % 10 == 2) return true;
		num /= 10;
	}
	return false;
} 

int main(void) {
	int cnt = 0;
	for (int i = 1; i <= 2017; i++) {
		if (judge(i)) continue;
		for (int j = i + 1; j <= 2018; j++) {
			if (judge(j)) continue;
			for (int k = j + 1; k <= 2019; k++) {
				if (judge(k)) continue;
				if (i + j + k == 2019) cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}
