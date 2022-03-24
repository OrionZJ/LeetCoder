// 2020�괺���ڼ䣬��һ����������������˴�ҵ�ע�⣺
// 2020��2��2�ա�
// ��Ϊ�����������ڰ���yyyymmdd���ĸ�ʽд��һ��8λ����20200202��
// ǡ����һ����������
// ���ǳ������������ǻ������ڡ�
// ���˱�ʾ20200202�ǡ�ǧ��һ�������������ӡ�
// �Դ�С���ܲ���ͬ����Ϊ����2��֮�������һ���������ڣ�20211202��2021��12��2�ա�
// Ҳ���˱�ʾ20200202����������һ���������ڣ�����һ��ABABBABA�͵Ļ������ڡ�
// �Դ�С��Ҳ����ͬ����Ϊ��Լ100������������һ��ABABBABA�͵Ļ������ڣ�
// 21211212��2121��12��12�ա�
// �㲻�ϡ�ǧ��һ�����������㡰ǧ����������
// ����һ��8λ�������ڣ�������������֮����һ���������ں���һ��ABABBABA�͵Ļ������ڸ�����һ�졣

#include <bits/stdc++.h>
using namespace std;

vector<int> int2str(int year, int month, int day) {
	vector<int> date(8, 0);
	date[0] = year / 1000;
	date[1] = year % 1000 / 100;
	date[2] = year % 100 / 10;
	date[3] = year % 10;
	date[4] = month / 10;
	date[5] = month % 10;
	date[6] = day / 10;
	date[7] = day % 10;
	return date;
}

void printDate(vector<int> date) {
	for (int i = 0; i < 8; i++) {
		cout << date[i];
	}
}
 
bool ifHui(vector<int> date) {
	int i = 0, j = 7;
	while (i < j) {
		if (date[i] != date[j]) return false;
		i++, j--;
	}
	return true;
}

bool ifAB(vector<int> date) {
	if (!ifHui(date)) return false;
	if (date[0] == date[2] && date[1] == date[3]) {
		return true;
	}
	return false;	
}

int main(void) {
	int date;
	cin >> date;
	int monthDay[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int year = date / 10000;
	int month = date % 10000 / 100;
	int day = date % 100;
	bool huiwen = false;
	bool abab = false;
	bool enter = true;
	while (1) {
		if (enter) {
			for (int i = month; i <= 12; i++) {
				for (int j = day + 1; j <= monthDay[i]; j++) {
					if (!((year % 100 == 0 && year % 400 == 0) || year % 4 == 0)) {
						if (i == 2 && j == 29) break;
					}
					vector<int> tmp = int2str(year, i, j);
					if (ifHui(tmp)) {
						printDate(tmp);
						cout << ' ';
					}
					if (ifAB(tmp)) {
						printDate(tmp);
						return 0;	
					}
				} 
			}
			enter = false;
			year++;
		}
		for (int i = 1; i <= 12; i++) {
			for (int j = 1; j <= monthDay[i]; j++) {
				if (!((year % 100 == 0 && year % 400 == 0) || year % 4 == 0)) {
					if (i == 2 && j == 29) break;
				}
				vector<int> tmp = int2str(year, i, j);
				if (ifHui(tmp) && !huiwen) {
					printDate(tmp);
					cout << '\n';
					huiwen = true;
				}
				if (ifAB(tmp) && !abab) {
					printDate(tmp);
					abab = true;
					return 0;	
				}
			}
		}
		year++;
		if (year > 9999) return 0;
	}
	return 0;
} 
