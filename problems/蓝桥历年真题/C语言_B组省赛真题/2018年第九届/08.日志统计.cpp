/*小明维护着一个程序员论坛。现在他收集了一份"点赞"日志，日志共有N行。其中每一行的格式是：

ts id

表示在ts时刻编号id的帖子收到一个"赞"。
现在小明想统计有哪些帖子曾经是"热帖"。如果一个帖子曾在任意一个长度为D的时间段内收到不少于K个赞，小明就认为这个帖子曾是"热帖"。
具体来说，如果存在某个时刻T满足该帖在[T, T+D)这段时间内(注意是左闭右开区间)收到不少于K个赞，该帖就曾是"热帖"。
给定日志，请你帮助小明统计出所有曾是"热帖"的帖子编号。
第一行包含三个整数N、D和K。
以下N行每行一条日志，包含两个整数ts和id。

对于50%的数据，1 <= K <= N <= 1000
对于100%的数据，1 <= K <= N <= 100000 0 <= ts <= 100000 0 <= id <= 100000
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
