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
        //去掉多余空格：

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
};