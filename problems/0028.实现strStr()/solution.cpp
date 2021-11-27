class Solution {
public:
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
        return -1;
    }
};