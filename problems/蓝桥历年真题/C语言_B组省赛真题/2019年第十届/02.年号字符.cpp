// С������ĸ A��Ӧ���� 1��B��Ӧ 2���Դ����ƣ��� Z��Ӧ 26��
// ���� 27���ϵ����֣�С������λ�����λ���ַ�������Ӧ��
// ���� AA��Ӧ27��AB��Ӧ28��AZ��Ӧ52��LQ��Ӧ329��
// ����2019��Ӧ���ַ�����ʲô��

#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int beg = 26 * 26 + 26;
	for (char i = 'A'; i <= 'Z'; i++) {
		for (char j = 'A'; j <= 'Z'; j++) {
			for (char k = 'A'; k <= 'Z'; k++) {
				beg++;
				if (beg == 2019) {
					cout << i << j << k ;
					return 0;
				}
				
			}
		}
	}
	return 0;
} 

