/*
小明刚刚找到工作，老板人很好，只是老板夫人很爱购物。
老板忙的时候经常让小明帮忙到商场代为购物。小明很厌烦，但又不好推辞。
这不，XX大促销又来了！老板夫人开出了长长的购物单，都是有打折优惠的。
小明也有个怪癖，不到万不得已，从不刷卡，直接现金搞定。
现在小明很心烦，请你帮他计算一下，需要从取款机上取多少现金，才能搞定这次购物。
取款机只能提供100元面额的纸币。小明想尽可能少取些现金，够用就行了。 
你的任务是计算出，小明最少需要取多少现金。
以下是让人头疼的购物单，为了保护隐私，物品名称被隐藏了。
*/

#include <bits/stdc++.h>
using namespace std;

int main(void) {
	string name;
	int money = 0;
	while (cin >> name && name != " ") {
		float pri;
		int dis;
		cin >> pri >> dis;
		float after = pri * (dis * 0.01);
		money += after;
		cout << money << " ";
	}
	
	return 0;
}
