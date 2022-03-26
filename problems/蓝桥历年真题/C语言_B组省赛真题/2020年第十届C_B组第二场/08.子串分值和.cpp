// 对于一个字符串 S，我们定义 S 的分值 f (S ) 为 S 中出现的不同的字符个
// 数。例如 f (”aba”) = 2， f (”abc”) = 3, f (”aaa”) = 1。
// 现在给定一个字符串 S [0::n ? 1]（长度为 n），请你计算对于所有 S 的非空
// 子串 S [i:: j](0 ≤ i ≤ j < n)， f (S [i:: j]) 的和是多少。
// ababc
// 【样例输出】
// 28
// 【样例说明】
// 子串 f值
// a 1
// ab 2
// aba 2
// abab 2
// ababc 3
// b 1
// ba 2
// bab 2
// babc 3
// a 1
// ab 2
// abc 3
// b 1
// bc 2
// c 1

#include <bits/stdc++.h>
using namespace std;

int judge(string s, int beg, int end) {
	vector<int> used(52, 0);
	int ret = 0;
	for (int i = beg; i <= end; i++) {
		if (used[s[i] - 'a'] == 0) {
			ret++;
			used[s[i] - 'a'] = 1;
		}
	}
	return ret;
}

int main(void) {
	string s;
	cin >> s;
	int sum = 0;
	for (int i = 0; i < s.size(); i++) {
		for (int j = i; j < s.size(); j++) {
			sum += judge(s, i, j);
		}
	}
	cout << sum;
	return 0;
} 
