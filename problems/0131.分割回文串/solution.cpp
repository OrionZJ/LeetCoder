class Solution {
private:
    vector<string> path;
    vector<vector<string>> result;
public:
    void backTracking(string s, int startIndex) {
        if (startIndex >= s.size()) {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i < s.size(); i++) {
            if (isPalindrome(s, startIndex, i)) {
                string str = s.substr(startIndex, i - startIndex + 1);
                path.push_back(str);
            } else continue;
            backTracking(s, i + 1);
            path.pop_back();
        }
    }

    bool isPalindrome(string s, int startIndex, int endIndex) {
        for (int i = startIndex, j = endIndex; i < j; i++, j--) {
            if (s[i] != s[j]) return false;
        }
        return true;
    }

    vector<vector<string>> partition(string s) {
        path.clear();
        result.clear();
        backTracking(s, 0);
        return result;
    }
};