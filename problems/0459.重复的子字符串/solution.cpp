//数组长度减去最长相同前后缀的长度相当于是第一个周期的长度，也就是一个周期的长度
//如果这个周期可以被整除，就说明整个数组就是这个周期的循环

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int next[s.size()];
        getNext(next, s);
        if (next[s.size() - 1] !=0 && s.size() % (s.size() - (next[s.size() - 1])) == 0)
            return true;
        else return false;
    }

    void getNext(int *next, const string &s) {
        int j = 0;
        next[0] = 0;
        for (int i = 1; i < s.size(); i++) {
            while (j > 0 && s[i] != s[j]) {
                j = next[j - 1];
            }
            if (s[j] == s[i]) {
                j++;
            }
            next[i] = j;
        }
    }
};