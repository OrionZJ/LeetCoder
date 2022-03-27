// 2020年春节期间，有一个特殊的日期引起了大家的注意：
// 2020年2月2日。
// 因为如果将这个日期按“yyyymmdd”的格式写成一个8位数是20200202，
// 恰好是一个回文数。
// 我们称这样的日期是回文日期。
// 有人表示20200202是“千年一遇”的特殊日子。
// 对此小明很不认同，因为不到2年之后就是下一个回文日期：20211202即2021年12月2日。
// 也有人表示20200202并不仅仅是一个回文日期，还是一个ABABBABA型的回文日期。
// 对此小明也不认同，因为大约100年后就能遇到下一个ABABBABA型的回文日期：
// 21211212即2121年12月12日。
// 算不上“千年一遇”，顶多算“千年两遇”。
// 给定一个8位数的日期，请你计算该日期之后下一个回文日期和下一个ABABBABA型的回文日期各是哪一天。

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
