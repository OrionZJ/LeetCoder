// 一般的排序有许多经典算法，如快速排序、希尔排序等。
// 但实际应用时，经常会或多或少有一些特殊要求。
// 我们没必要套用那些经典算法，可以根据实际情况建立更好的解法。
// 比如，对一个整型数组中的数字进行分类排序：
// 使得负数都靠左端，正数都靠右端，0在中部。
// 注意问题的特点是：负数区域和正数区域内并不要求有序。
// 可以利用这个特点通过1次线性扫描就结束战斗！
// 以下的程序实现了该目标。
// 其中x指向待排序的整型数组，len是数组的长度。

#include <bits/stdc++.h>
using namespace std;

void sort3p(int *x,int len)
{ 
	int p=0;
	int left=0;
 	int right=len-1;
 	int t;
 	while(p<=right)
    { 
    	if(x[p]<0)
        { 
        	t=x[left];  x[left]=x[p];  x[p]=t;  left++;  p++; 
       	}
	  	else if(x[p]>0) 
	  	{ 
	  		t=x[right];  x[right]=x[p];  x[p]=t;  right--; 
	  	}
		else 
		{ 
            x[p++]=0;    //填空位置
		}
	}
}

int main(void) {
    int x[]={-1,1,0,-2,1,2,-1,-3,1};
    sort3p(x,8);
    for (int i = 0; i < 8; i++)
    {
        cout << x[i];
    }
    return 0;
}