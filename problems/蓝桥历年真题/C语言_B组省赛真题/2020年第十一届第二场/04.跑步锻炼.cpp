// 小蓝每天都锻炼身体。正常情况下，小蓝每天跑1千米。
// 如果某天是周一或者月初（1日），
// 为了激励自己，小蓝要跑2千米。
// 如果同时是周一或月初，小蓝也是跑2千米。
// 小蓝跑步已经坚持了很长时间，
// 从2000年1月1日周六（含）到2020年10月1日周四（含）。
// 请问这段时间小蓝总共跑步多少千米？

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
