class Solution {
public:
    string reverseStr(string s, int k) {
        int slowPointer = 0;
        int fastPointer = 0;
        int n = s.length();
        int midPointer;
        while (slowPointer < n - 1) {
            if (slowPointer + (2*k - 1) > n - 1) {
                fastPointer = n - 1;
                midPointer = slowPointer + (k - 1);
            } 
            else if (slowPointer + (k - 1) > n - 1 && slowPointer + (2*k - 1) <= n - 1) {
                fastPointer = n - 1;
                midPointer = fastPointer;
            } else {
                fastPointer = slowPointer + 2*k;
                midPointer = slowPointer + (k - 1);
            }

            while (slowPointer < midPointer) {
                char temp = s[slowPointer];
                s[slowPointer] = s[midPointer];
                s[midPointer] = temp;
                slowPointer++; midPointer--;
            }
            slowPointer = fastPointer;
        }
    return s;
    }
};