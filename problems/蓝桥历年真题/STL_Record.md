# next_permutation

把区间内数组的数据改为他们全排列的下一个排列

```c++
#include <algorithm>

bool next_permutation(iterator start,iterator end)    //左闭右开区间
```
当当前序列不存在下一个排列时，函数返回false，否则返回true；

prev_permutation同理，求上一个排列。

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

# rand()函数

```c
int rand(void)
```

该函数返回一个范围在 0 到 RAND_MAX 之间的整数值。

```c++
// 输出 0 到 49 之间的随机数
printf("%d\n", rand() % 50);
```

# 递归算法

运用递归算法解决计算可能情况问题

[例题：奇怪的比赛](C语言_B组省赛真题\2012年第三届C_B组\04.奇怪的比赛.cpp)

[例题：第39级台阶](C语言_B组省赛真题\2013年第四届C_B组\03.第39级台阶.cpp)

#  `s.substr(pos, len)`

返回值： string，包含s中从pos开始的len个字符的拷贝

pos的默认值是0，len的默认值是s.size() - pos，即不加参数会默认拷贝整个s

# `system("pause");`

防止窗口关闭看不了代码
