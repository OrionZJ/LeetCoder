/*С��ά����һ������Ա��̳���������ռ���һ��"����"��־����־����N�С�����ÿһ�еĸ�ʽ�ǣ�

ts id

��ʾ��tsʱ�̱��id�������յ�һ��"��"��
����С����ͳ������Щ����������"����"�����һ��������������һ������ΪD��ʱ������յ�������K���ޣ�С������Ϊ�����������"����"��
������˵���������ĳ��ʱ��T���������[T, T+D)���ʱ����(ע��������ҿ�����)�յ�������K���ޣ�����������"����"��
������־���������С��ͳ�Ƴ���������"����"�����ӱ�š�
��һ�а�����������N��D��K��
����N��ÿ��һ����־��������������ts��id��

����50%�����ݣ�1 <= K <= N <= 1000
����100%�����ݣ�1 <= K <= N <= 100000 0 <= ts <= 100000 0 <= id <= 100000
*/

#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int N, D, K;
	cin >> N >> D >> K;
	vector<vector<int> > data(1000010, vector<int>(1,0));
	vector<int> ret;
	for (int i = 0; i < N; i++) {
		int ts, id;
		cin >> ts >> id;
		data[id].push_back(ts);
	}
	for (int i = 0; i < 1000010; i++) {
		sort(data[i].begin(), data[i].end());
		for (int m = 1; m < data[i].size(); m++) {
			int cnt = 0;
			for (int n = m; n < data[i].size(); n++) {
				if (data[i][n] - data[i][m] < D) cnt++;
				if (cnt >= K) {
					data[i][0] = 1;
					ret.push_back(i);
					break;
				}
			}
			if (cnt >= K) break;
		}
	} 
	for (int i = 0; i < ret.size(); i++) {
		cout << ret[i] << "\n";
	}
	return 0;
} 
