// 小明用字母 A对应数字 1，B对应 2，以此类推，用 Z对应 26。
// 对于 27以上的数字，小明用两位或更长位的字符串来对应，
// 例如 AA对应27，AB对应28，AZ对应52，LQ对应329。
// 请问2019对应的字符串是什么？

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

