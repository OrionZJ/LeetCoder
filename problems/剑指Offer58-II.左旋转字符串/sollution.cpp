class Solution {
public:
    string reverseLeftWords(string s, int n) {
        //先整体反转
        int left = 0;
        int right = s.size() - 1;
        reverse(left,right,s);
        //再局部反转 
        right = right - n;
        reverse(left,right,s);

        left = right + 1;
        right = s.size() - 1;
        reverse(left,right,s);
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