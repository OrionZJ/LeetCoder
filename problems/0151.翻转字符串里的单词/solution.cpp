class Solution {
public:
    string reverseWords(string s) {
        int left = 0;
        int right = s.size() - 1;
        reverse(left,right,s);
        
    }

    void reverse(int left, int right, string &s) {
        while (left < right) {
            swap(left,right,s);
            left++; right--;
        }        
    }

    void swap(int left, int right, string &s) {
        s[left] ^= s[right];
        s[right] ^= s[left];
        s[left] ^= s[right];
    }
};