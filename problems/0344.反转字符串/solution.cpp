class Solution {
public:
    void reverseString(vector<char>& s) {
        vector<char>::iterator front = s.begin();
        vector<char>::iterator behind = s.end() - 1;
        while (front < behind) {
            swap_1(*front,*behind);
            front++;
            behind--;
        }
    }

    void swap_1(char &a, char &b) {
        char temp = a;
        a = b;
        b = temp;
    }

    void swap_2(char &a, char &b) {
        a ^= b;
        b ^= a;
        a ^= b;
    }
};

