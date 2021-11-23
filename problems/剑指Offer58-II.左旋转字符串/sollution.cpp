class Solution {
public:
    string reverseLeftWords(string s, int n) {
        //先整体反转
        reverse(0,s.size() - 1,s);
        //再局部反转 
        reverse(0,s.size() - 1 - n,s);
        reverse(s.size() - n,s.size() - 1,s);
        return s;
    }
    //交换两下角标对应元素
    void swap(int left, int right, string &s) {
        s[left] ^= s[right];
        s[right] ^= s[left];
        s[left] ^= s[right];
    }
    //闭区间内元素逆转
    void reverse(int left, int right, string &s) {
        while (left < right) {
            swap(left,right,s);
            left++; right--;
        }
    }
};