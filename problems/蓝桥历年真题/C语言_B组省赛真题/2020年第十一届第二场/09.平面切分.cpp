// ƽ������N ��ֱ�ߣ����е�i��ֱ����y = Ai x+Bi
// �������Щֱ�߽�ƽ��ֳ��˼������֡�
// �������ʽ��
// ����ĵ�һ�а���һ������N, ����N�У���������֤�� Ai��Bi
// �������ʽ�� һ�����������
// ���������롿
// 3
// 1 1
// 2 2
// 3 3
// �����������
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
				}  // ֱ���غ�
				else continue;  // ֱ��ƽ�� 
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
