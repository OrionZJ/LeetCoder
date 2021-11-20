class Solution {
public:
    string reverseWords(string s) {
        int left = 0;
        int right = s.size() - 1;
        //反转整个
        reverse(left,right,s);
        right = left;
        //把单词内的字母顺序反转回来
        while (left < s.size() - 1) {
            while (s[left] == ' ' && left < s.size() - 1) left++;
            right = left;
            while (s[right] != ' ' && right < s.size()) right++;   //形成左闭右开区间，right可以越界一个单位
            reverse(left,right - 1,s);
            left = right;
        }
        //去掉多余空格
        removeExtraSpaces(s);
        return s;
    }
    //反转闭区间
    void reverse(int left, int right, string &s) {
        while (left < right) {
            swap(left,right,s);
            left++; right--;
        }        
    }
    //互换
    void swap(int left, int right, string &s) {
        s[left] ^= s[right];
        s[right] ^= s[left];
        s[left] ^= s[right];
    }

    void removeExtraSpaces(string& s) {
        int slowIndex = 0, fastIndex = 0; // 定义快指针，慢指针
        // 去掉字符串前面的空格
        while (s.size() > 0 && fastIndex < s.size() && s[fastIndex] == ' ') {
            fastIndex++;
        }
        for (; fastIndex < s.size(); fastIndex++) {
            // 去掉字符串中间部分的冗余空格
            if (fastIndex - 1 > 0
                    && s[fastIndex - 1] == s[fastIndex]
                    && s[fastIndex] == ' ') {
                continue;
            } else {
                s[slowIndex++] = s[fastIndex];
            }
        }
        if (slowIndex - 1 > 0 && s[slowIndex - 1] == ' ') { // 去掉字符串末尾的空格
            s.resize(slowIndex - 1);
        } else {
            s.resize(slowIndex); // 重新设置字符串大小
        }
    }
};