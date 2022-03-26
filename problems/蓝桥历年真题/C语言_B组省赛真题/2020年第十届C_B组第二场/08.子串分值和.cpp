// ����һ���ַ��� S�����Ƕ��� S �ķ�ֵ f (S ) Ϊ S �г��ֵĲ�ͬ���ַ���
// �������� f (��aba��) = 2�� f (��abc��) = 3, f (��aaa��) = 1��
// ���ڸ���һ���ַ��� S [0::n ? 1]������Ϊ n������������������ S �ķǿ�
// �Ӵ� S [i:: j](0 �� i �� j < n)�� f (S [i:: j]) �ĺ��Ƕ��١�
// ababc
// �����������
// 28
// ������˵����
// �Ӵ� fֵ
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
