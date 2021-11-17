class Solution {
public:
    string reverseStr(string s, int k) {
        int slowPointer = 0;
        int fastPointer = 0;
        int n = s.length();
        int midPointer;
        while (slowPointer < n - 1) {
            fastPointer = min(n - 1, slowPointer + 2 * k );
            midPointer = min(n - 1, slowPointer + (k - 1) );
            while (slowPointer < midPointer) {    //对该闭区间进行反转
                s[slowPointer] ^= s[midPointer];
                s[midPointer] ^= s[slowPointer];
                s[slowPointer] ^= s[midPointer];
                slowPointer++; midPointer--;
            }
            slowPointer = fastPointer;
        }
        return s;
    }

    //取两个元素最小值
    int min(int a, int b) {
        return a < b ? a : b;
    }
    
};