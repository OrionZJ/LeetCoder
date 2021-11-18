class Solution {
public:
    string replaceSpace(string s) {
        int cnt = 0;
        int fastPointer = s.size() - 1;
        int slowPointer;
        int oldSize = s.size();
        //通过遍历计算新字符串的大小
        for (int i = 0; i < oldSize; i++) {
            if (s[i] == ' ') {
                cnt += 3;
            } else {
                cnt++;
            }
        }
        s.resize(cnt);    //扩充字符串s的大小，也就是每个空格替换成"%20"之后的大小
        slowPointer = cnt - 1;
        //从后往前依次替换空格
        for (int i = oldSize - 1; i >= 0 && slowPointer >= 0; i--) {
            if (s[i] == ' ') {
                s[slowPointer--] = '0';
                s[slowPointer--] = '2';
                s[slowPointer--] = '%';
            } else {
                s[slowPointer--] = s[i];
            }
        }
        return s;
    }
};