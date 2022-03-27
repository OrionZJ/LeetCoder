// 平面上有N 条直线，其中第i条直线是y = Ai x+Bi
// 请计算这些直线将平面分成了几个部分。
// 【输入格式】
// 输入的第一行包含一个整数N, 以下N行，包含两个证书 Ai，Bi
// 【输出格式】 一个整数代表答案
// 【样例输入】
// 3
// 1 1
// 2 2
// 3 3
// 【样例输出】
// 6

#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	int lines[1010][2];
	int ans = 1;
	for (int i = 0; i < n; i++) {
		cin >> lines[i][0] >> lines[i][1];
		set<pair<long double, long double> > points;
		bool chonghe = false;
		for (int j = 0; j < i; j++) {
			if (lines[i][0] == lines[j][0]) {
				if (lines[i][1] == lines[j][1]) {
					chonghe = true;
					break;	
				}  // 直线重合
				else continue;  // 直线平行 
			}
			pair<long double, long double> point;
			point.first = (lines[i][1] - lines[j][1]) / (lines[j][0] - lines[i][0]);
			point.second = point.first * lines[i][0] + lines[i][1];
			points.insert(point);
		}
		if (!chonghe) {
			ans += points.size() + 1;
		}
	}
	cout << ans;
	return 0;
} 
