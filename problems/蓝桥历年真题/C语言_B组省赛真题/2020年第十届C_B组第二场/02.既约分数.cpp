//���һ�������ķ��Ӻͷ�ĸ�����Լ����1��
//���������Ϊ��Լ������
//���磬3/4,5/2,1/8,7/1���Ǽ�Լ������
//���ʣ��ж��ٸ���Լ���������Ӻͷ�ĸ����1��2020֮�������������1��2020��

# include <bits/stdc++.h>
using namespace std;

int maxYue(int a, int b) {
	if (a % b == 0) return b;
	else return maxYue(b, a %b);	
}

int main(void) {
	int ans = 0;
	for (int i = 1; i <=2020; i++) {
		for (int j = 1; j <= 2020; j++) {
			if (maxYue(i, j) == 1) ans++;
		}
	}
	cout << ans;
	return 0;
} 
