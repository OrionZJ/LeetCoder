# next_permutation

```c++
#include <algorithm>

bool next_permutation(iterator start,iterator end)    //左闭右开区间
```
当当前序列不存在下一个排列时，函数返回false，否则返回true；
[例题：古堡算式](C语言_B组省赛真题/2012年第三届C_B组蓝桥杯省赛真题/02.古堡算式.cpp)

# 比较浮点数

> The important rule to remember is that powers of two and integer multiples thereof can be perfectly represented. everything else is an approximation.

在比较的时候需要用一个很小的数值来进行比较（二分法的思想），当二者之差小于这个很小的数时，就认为二者是相等的了，而不能直接用==或=比较。这个很小的数，称为精度。

精度由计算过程中需求而定。比如一个常用的精度为`1e-6`，也就是`0.000001`。

所以对于两个浮点数a,b，如果要比较大小，那么常常会设置一个精度
如果`fabs(a-b)<=1e-6`，那么就是相等了。 

类似的判断大于的时候，就是`if(a>b && fabs(a-b)>1e-6)`。

判断小于的时候，就是`if(a<b&&fabs(a-b)>1e-6)`。

> fabs是求浮点数绝对值的函数。