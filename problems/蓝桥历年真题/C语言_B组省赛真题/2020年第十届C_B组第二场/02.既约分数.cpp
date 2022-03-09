//如果一个分数的分子和分母的最大公约数是1，
//这个分数称为既约分数。
//例如，3/4,5/2,1/8,7/1都是既约分数。
//请问，有多少个既约分数，分子和分母都是1到2020之间的整数（包括1和2020）

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
