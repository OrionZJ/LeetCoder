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

    //使用位运算交换两数，无需使用第三个数
    void swap_2(char &a, char &b) {
        a ^= b;
        b ^= a;
        a ^= b;
    }

    void swap_int(int &a, int &b) {
        a = a + b;
        b = a - b;
        a = a - b;
    }
};

