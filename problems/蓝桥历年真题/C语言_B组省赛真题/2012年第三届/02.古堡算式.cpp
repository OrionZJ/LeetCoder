// 福尔摩斯到某古堡探险，看到门上写着一个奇怪的算式：ABCDE*?=EDCBA。
// 他对华生说：“ABCDE应该代表不同的数字，问号也代表某个数字！” 
// 华生：“我猜也是！”，于是，两人沉默了好久，还是没有算出合适的结果来。 
// 请你利用计算机的优势，找到破解的答案，把ABCDE所代表的数字写出来。

// #include <bits/stdc++.h>
// using namespace std;

// int main(void) {
//     int x;
//     for (x = 10000; x < 100000; x++) {
//         int a = x / 10000;
//         int b = (x / 1000) % 10;
//         int c = (x / 100) % 10;
//         int d = (x / 10) % 10;
//         int e = x % 10;

//         for (int i = 1; i < 10; i++) {
//             if (x*i == e*10000 + d*1000 + c*100 + b*10 +a)
//                 cout << a << b << c << d << e << endl;
//         }
        
//     }
// }

#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int numArray[10] = {0,1,2,3,4,5,6,7,8,9};
	while(next_permutation(numArray,numArray+10))
	{
		if(numArray[0]!=0&&numArray[4]!=0)
		{
			int leftVal = numArray[0]*10000+numArray[1]*1000+numArray[2]*100+numArray[3]*10+numArray[4];
			int rightVal = numArray[4]*10000+numArray[3]*1000+numArray[2]*100+numArray[1]*10+numArray[0];
			int temp = numArray[5];
			if(leftVal*temp==rightVal)
			{
				cout << numArray[0] << numArray[1] << numArray[2] << numArray[3] << numArray[4] <<endl;
			
				break;
			}
		}
	}
	return 0;
}
