// 如下的代码判断needle_start指向的串是否为haystack_start指向的串的前缀，
// 如不是，则返回NULL。
// 比如："abcd1234"就包含了"abc"为前缀。

// char *prefix(char *haystack_start,char *needle_start)
// { 
// 	char *haystack=haystack_start;
// 	char *needle=needle_start;
// 	while(*haystack&&*needle)
// 	{
// 		if(_____________________) return NULL;  //填空位置
// 	}
// 	if(*needle) return NULL;
// 	return haystack_start;
// }

#include <bits/stdc++.h>
using namespace std;

char *prefix(char *haystack_start,char *needle_start)
{ 
	char *haystack=haystack_start;
	char *needle=needle_start;
	while(*haystack&&*needle)
	{
		if(*(needle++) != *(haystack++) ) return NULL;  //填空位置
	}
	if(*needle) return NULL;
	return haystack_start;
}

int main()
{
	char haystack_start[] = "abcd123";
	char needle_start[] = "abcd";
	char *ans = prefix(haystack_start,needle_start);
	cout <<ans;
}
