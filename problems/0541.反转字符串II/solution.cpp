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
            while (slowPointer < midPointer) {
                s[slowPointer] ^= s[midPointer];
                s[midPointer] ^= s[slowPointer];
                s[slowPointer] ^= s[midPointer];
                slowPointer++; midPointer--;
            }
            slowPointer = fastPointer;
        }
    return s;
    }

    int min(int a, int b) {
        return a < b ? a : b;
    }
    
};