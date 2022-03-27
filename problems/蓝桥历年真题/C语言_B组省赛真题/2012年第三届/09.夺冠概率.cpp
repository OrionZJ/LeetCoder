// 足球比赛具有一定程度的偶然性，弱队也有战胜强队的可能。
// 假设有甲、乙、丙、丁四个球队，根据他们过去比赛的成绩，得出每个队与另一个队对阵时取胜的概率表：
//    甲     乙    丙    丁
// 甲  -    0.1   0.3   0.5
// 乙 0.9    -    0.7   0.4
// 丙 0.7   0.3    -    0.2
// 丁 0.5   0.6   0.8    -
// 数据含义：甲对乙的取胜概率为0.1，丙对乙的胜率为0.3，…。
// 现在要举行一次锦标赛，双方抽签，分两个组比，获胜的两个队再争夺冠军（参见下图）。
// 请你进行10万次模拟，计算出甲队夺冠的概率
#include <bits/stdc++.h>
using namespace std;

int main(void) {
	
	long double totalP = 0;
	for (int i = 0; i < 100000; i++) {
		int situation = rand() % 3;
		double p = 0;
		switch (situation) {
			case 0:
				p = 0.1 * (0.2 * 0.3 + 0.8 * 0.5);
				break;
				
			case 1:
				p = 0.3 * (0.4 * 0.1 + 0.6 * 0.5);
				break;
				
			case 2:
				p = 0.5 * (0.7 * 0.1 + 0.3 * 0.3);
				break;				
		}
		totalP += p;
	}
	long double everage = totalP / 100000;
	cout << everage;
	return 0;
} 
