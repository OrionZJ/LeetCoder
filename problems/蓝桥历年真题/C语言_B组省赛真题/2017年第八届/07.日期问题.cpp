/*
С����������һ����ʷ���ס���Щ��ʷ�����г����˺ܶ����ڡ�С��֪����Щ���ڶ���1960��1��1����2059��12��31�ա�
��С��ͷ�۵��ǣ���Щ���ڲ��õĸ�ʽ�ǳ���ͳһ���в�����/��/�յģ��в�����/��/��ģ����в�����/��/��ġ�
�����鷳���ǣ����Ҳ��ʡ����ǰ��λ��ʹ�������ϵ�һ�����ڣ����ںܶ���ܵ����������Ӧ��
����02/03/04��������2002��03��04�ա�2004��02��03�ջ�2004��03��02�ա�
����һ�������ϵ����ڣ����ܰ���С���ж�����Щ���ܵ����ڶ����Ӧ��
����
һ�����ڣ���ʽ��"AA/BB/CC"�� (0 <= A, B, C <= 9)
���
������ɸ�����ͬ�����ڣ�ÿ������һ�У���ʽ��"yyyy-MM-dd"��������ڰ����絽�����С�
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
