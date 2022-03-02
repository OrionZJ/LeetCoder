# 首页
LeetCode刷题记录与算法整理

努力刷题中......

# 数组
  - [二分法](problems/0704.二分查找/二分查找.md)

  - [双指针法](problems/0027.移除元素/移除元素.md)

  - [滑动窗口法](problems/0977.有序数组的平方/有序数组的平方.md)

  - [模拟过程](problems/0059.旋转矩阵/旋转矩阵.md)

  - **总结**：**循环不变量原则**

    只有在循环中坚持对区间的定义，才能清楚的把握循环中的各种细节

# 链表
  - [虚拟头结点](problems/0203.移除链表元素/移除链表元素.md)
  - [双指针](problems/0206.反转链表/反转链表.md)
    - 提前调整指针相对位置，然后再移动指针
  - **总结**：
    - 通过虚拟头结点解决头结点为NULL的情况
    - 巧设双指针大大降低时间复杂度
    - 通过数学寻找规律完成解题

# 字符串
字符串是若干字符组成的有限序列，也可以理解为是一个字符数组。

在C语言中，把一个字符串存入一个数组时，也把结束符 '\0'存入数组，并以此作为该字符串是否结束的标志。

在C++中，提供一个string类，string类会提供 size接口，可以用来判断string类字符串是否结束，就不用'\0'来判断是否结束。

vector< char > 和 string 在基本操作上没有区别，但是 string提供更多的字符串处理的相关接口，例如string 重载了+，而vector却没有。

  - 反转顺序（[互换元素](problems/0344.反转字符串/反转字符串.md)）
  - [替换空格](problems/剑指Offer05.替换空格/solution.cpp)
  - [整体＋局部](problems/剑指Offer58-II.左旋转字符串/solution.cpp)（反转）－－不申请额外空间完成操作
  - [KMP算法](problems/0028.实现strStr()/KMP算法.md)
  - **总结**：
    - 在互换元素的过程中通过位运算减少占用空间
    - 双指针法替换空格减少内存占用避免每次添加元素都要将添加元素之后的所有元素向后移动
    - 先整体反转，后局部反转实现特定反转要求
    - KMP算法最长相等前后缀的使用

# 动态规划

动态规划五部曲：

1. 确定dp数组（dp table）以及下标的含义
2. 确定递推公式
3. dp数组如何初始化
4. 确定遍历顺序
5. 举例推导dp数组

经典问题：

- [斐波那契](problems/0509.斐波那契数/斐波那契数.md)
- [爬楼梯](problems/0746.使用最小花费爬楼梯/使用最小花费爬楼梯.md)
- [不同路径](problems/0062.不同路径/不同路径.md)
- 背包问题
  - [01背包](problems/0416.分割等和子集/01背包问题.md)
  - [完全背包](problems/0518.零钱兑换II/完全背包.md)
- [打家劫舍](problems/0198.打家劫舍/打家劫舍.md)
- [股票问题](problems/0121.买卖股票的最佳时机/买卖股票.md)
- 子序列问题