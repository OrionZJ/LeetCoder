/*
��ͯ��������KλС���ѵ�С�������͡�С���ó�����ص��ɿ����д�С�����ǡ�
С��һ����N���ɿ��������е�i����Hi x Wi�ķ�����ɵĳ����Ρ�

Ϊ�˹�ƽ�����С����Ҫ���� N ���ɿ������г�K���ɿ����ָ�С�����ǡ��г����ɿ�����Ҫ���㣺

��״�������Σ��߳�������
��С��ͬ
����һ��6x5���ɿ��������г�6��2x2���ɿ�������2��3x3���ɿ�����
��ȻС�����Ƕ�ϣ���õ����ɿ��������ܴ����ܰ�СHi��������ı߳��Ƕ���ô��
����
��һ�а�����������N��K��(1 <= N, K <= 100000)
����N��ÿ�а�����������Hi��Wi��(1 <= Hi, Wi <= 100000)
���뱣֤ÿλС���������ܻ��һ��1x1���ɿ�����
���
����г����������ɿ��������ܵı߳���

�������룺
2 10
6 5
5 6
���������
2
*/

#include <bits/stdc++.h>
using namespace std;

int sep(int a, int h, int w) {
	return (h / a) * (w / a);
}

int main(void) {
	int N, K;
	cin >> N >> K;
	vector<vector<int> > data(N, vector<int>(2));
	for (int i = 0; i < N; i++) cin >> data[i][0] >> data[i][1];
	int a = 1;
	int cnt = INT_MAX;
	int ret = 0;
	for (a = 1; 1; a++) {
		int num = 0;
		for (int i = 0; i < N; i++) {
			num += sep(a, data[i][0], data[i][1]);
		}
		if (num <= cnt && num >= K) {
			cnt = num;
			ret = a;
		}
		if (num < K) break;
	}	
	cout << ret;
	return 0;
}
