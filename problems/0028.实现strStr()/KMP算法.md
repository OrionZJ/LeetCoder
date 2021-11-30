# 28.实现strStr()

[LeetCode链接](https://leetcode-cn.com/problems/implement-strstr/)

# 什么是KMP算法？

**快速模式匹配算法**，由这三位学者发明：Knuth，Morris和Pratt，取三位学者名字的首字母叫做KMP算法。

# 为什么使用KMP算法？

BF算法的实现过程是 "傻瓜式" 地用模式串（假定为子串的串）与文本串中的字符一一匹配，算法执行效率不高。

而KMP算法通过消除对文本串指针的回溯提高算法效率。

# next数组

先明确一下概念：

- **文本串** 需要从中找到特定词组的字符串
- **模式串** 要匹配的特定词组的字符串
- **前缀** 从第一个字符开始的不包含最后一个字符的字符串
- **后缀** 从最后一个字符开始的不包含一个字符的字符串
- **最长相等前后缀** 前缀与后缀中最长的内容相同的字符串长度
- **前缀表** 由最长相等前后缀构成的表，常储存于Next数组中

举个例子：

    文本串：aabaabaafa
    模式串：aabaaf

- `a` **最长相等前后缀**：0；
- `aa` 前缀：a， 后缀：a，**最长相等前后缀**：1；
- `aab` 前缀：a、aa， 后缀：b、ab， **最长相等前后缀**：0；
- `aaba` 前缀：a、aa、aab， 后缀：a、ba、aba， **最长相等前后缀**：1；
- `aabaa` 前缀：a、aa、aab、aaba， 后缀：a、aa、baa、abaa， **最长相等前后缀**：2；
- `aabaaf` 前缀：a、aa、aab、aaba、aabaa， 后缀：f、af、aaf、baaf、abaaf， **最长相等前后缀**：0；
- 模式串的前缀表： `0 1 0 1 2 0`
- 模式串的一种Next数组构建：`0 1 0 1 2 0`
- 模式串的另一种Next数组构建： `-1 0 -1 0 1 -1`

以下是构建Next数组的代码：
```c++
void getNext(int *next, const string &s) {    //计算前缀表
    int j = 0;
    next[0] = 0;
    for (int i = 1; i < s.size(); i++) {    //遍历模式串
        while (j > 0 && s[i] != s[j]) {    //前后缀不同
            j = next[j - 1];    //j回退到上一匹配位置
        }
        if (s[i] == s[j]) {    //找到相同前后缀
            j++;    //i在for循环条件中自加
        }
        next[i] = j;    //最长相等前后缀恰好为j
    }
}
```
那怎么使用Next数组呢？

这里就先只说第一种Next数组构建方法的使用。

    文本串：a a b a a b a a f a
    模式串：a a b a a f
    前缀表：0 1 0 1 2 0

当文本串的第二个 `b` 与模式串的 `f` 不匹配时，指向模式串的指针就根据**前缀表**（f前一元素的最长相等前后缀）指向模式串对应位置（模式串的 `b` ）。这个位置的**下标**就是 `f` 前一元素的**最长相等前后缀**。

下面是代码实现：
```c++
int strStr(string haystack, string needle) {
    if (needle.size() == 0) return 0;
    int next[needle.size()];
    getNext(next, needle);    //计算前缀表
    int j = 0;
    for (int i = 0; i < haystack.size(); i++) {    //遍历文本串
        while (j > 0 && haystack[i] != needle[j]) {    //不匹配时j回退
            j = next[j - 1];
        }
        if (haystack[i] == needle[j]) {    //匹配时i、j同时后移
            j++;    //i自加位于for循环条件中
        }
        if (j == needle.size() ) {    //此处易错，此时文本串中出现模式串
            return i - (needle.size() - 1);    //返回
        }
    }
```