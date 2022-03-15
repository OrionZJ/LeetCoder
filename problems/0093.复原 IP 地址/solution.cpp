class Solution {
private:
    vector<string> result;
public:
    void backTracking(string &s, int startIndex, int pointNum) {
        if (pointNum == 3) {
            if (ifRational(s, startIndex, s.size() - 1)) {
                result.push_back(s);
            }
            return;
        }
        for (int i = startIndex; i < s.size(); i++) {
            if (ifRational(s, startIndex, i)) {
                s.insert(s.begin() + i + 1, '.');
                pointNum++;
                backTracking(s, i + 2, pointNum);
                pointNum--;
                s.erase(s.begin() + i + 1);
            } else break;
        }
    }

    bool ifRational(const string &s, int start, int end) {
        if (start > end) return false;
        if (s[start] == '0' && start != end) return false;
        int num = 0;
        for (int i = start; i <= end; i++) {
            if (s[i] < '0' || s[i] > '9') return false;
            num = num * 10 + (s[i] - '0');
            if (num > 255) return false;
        }
        return true;
    }

    vector<string> restoreIpAddresses(string s) {
        result.clear();
        if (s.size() > 12) return result;
        backTracking(s, 0, 0);
        return result;
    }
};