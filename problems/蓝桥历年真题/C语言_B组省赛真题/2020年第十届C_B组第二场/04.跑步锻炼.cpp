// С��ÿ�춼�������塣��������£�С��ÿ����1ǧ�ס�
// ���ĳ������һ�����³���1�գ���
// Ϊ�˼����Լ���С��Ҫ��2ǧ�ס�
// ���ͬʱ����һ���³���С��Ҳ����2ǧ�ס�
// С���ܲ��Ѿ�����˺ܳ�ʱ�䣬
// ��2000��1��1��������������2020��10��1�����ģ�������
// �������ʱ��С���ܹ��ܲ�����ǧ�ף�

#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int last = 0;
	int inspire = 0;
	int date[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	for (int year = 2000; year <= 2020; year++) {
		for (int month = 1; month <= 12; month++) {
			for (int day = 1; day <= date[month]; day++) {
				last++;
				if (day == 1 || (last - 3) % 7 == 0) {
					inspire += 2;
				} else inspire++;
				if (year == 2020 && month == 10 && day == 1) cout << inspire;
				if ((year % 4 != 0 && year != 2000)) {
					if (month == 2 && day == 28) break; 
				}
			}
		}
	}
//	cout << inspire;
	return 0;
}
