/*
小明正在整理一批历史文献。这些历史文献中出现了很多日期。小明知道这些日期都在1960年1月1日至2059年12月31日。
令小明头疼的是，这些日期采用的格式非常不统一，有采用年/月/日的，有采用月/日/年的，还有采用日/月/年的。
更加麻烦的是，年份也都省略了前两位，使得文献上的一个日期，存在很多可能的日期与其对应。
比如02/03/04，可能是2002年03月04日、2004年02月03日或2004年03月02日。
给出一个文献上的日期，你能帮助小明判断有哪些可能的日期对其对应吗？
输入
一个日期，格式是"AA/BB/CC"。 (0 <= A, B, C <= 9)
输出
输出若干个不相同的日期，每个日期一行，格式是"yyyy-MM-dd"。多个日期按从早到晚排列。
*/

#include <bits/stdc++.h>
using namespace std;

bool ifReasonable(int year, int mon, int day) {
	if (year <= 59) year += 2000;
	else year += 1900;
	bool ifRun = false;
	int run[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int pin[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
		ifRun = true;
	}
	if (mon < 1 || mon > 12) return false;
	if (ifRun) {
		if (day > 0 && day <= run[mon]) return true;
	} else {
		if (day > 0 && day <= pin[mon]) return true;
	}
	return false;
} 

int s2i(string s) {
	int g = s[1] - '0';
	int sh = s[0] - '0';
	int num = g + sh * 10;
	return num;
}

int main(void) {
	string s;
	cin >> s;
	string sy = s.substr(0, 2);
	string sm = s.substr(3, 2);
	string sd = s.substr(6, 2);
	int iy = s2i(sy);
	int im = s2i(sm);
	int id = s2i(sd);
	
	
	
	vector<long int> ans;
	bool a = ifReasonable(iy, im, id);
	if (a) {
		int tmp;
		if (iy <= 59) tmp = iy + 2000;
		else tmp =iy + 1900;
		ans.push_back(tmp * 10000 + im * 100 + id);
	}
	bool b = ifReasonable(id, iy, im);
	if (b) {
		int tmp;
		if (id <= 59) tmp = id + 2000;
		else tmp =id + 1900;
		ans.push_back(tmp * 10000 + iy * 100 + im);
	}
	bool c = ifReasonable(id, im, iy);
	if (c) {
		int tmp;
		if (id <= 59) tmp = id + 2000;
		else tmp =id + 1900;
		ans.push_back(tmp * 10000 + im * 100 + iy);
	}
	sort(ans.begin(), ans.end());
	
	for (int i = 0; i < ans.size(); i++) {
		if (i > 0 && ans[i] == ans[i - 1]) continue;
		int fy = ans[i] / 10000;
		int fm = ans[i] % 10000 / 100;
		int fd = ans[i] % 100;
		cout << fy << '-' ;
		if (fm < 10) cout << '0';
		cout << fm << '-' ;
		if (fd < 10) cout << '0';
		cout << fd;
		if (i < ans.size() - 1) cout << '\n';
	}
	return 0;
	}
