# 28.实现strStr()

[LeetCode链接](https://leetcode-cn.com/problems/implement-strstr/)

# 什么是KMP算法？

**快速模式匹配算法**，由这三位学者发明：Knuth，Morris和Pratt，取三位学者名字的首字母叫做KMP算法。

# 为什么使用KMP算法？

BF算法的实现过程是 "傻瓜式" 地用模式串（假定为子串的串）与文本串中的字符一一匹配，算法执行效率不高。
