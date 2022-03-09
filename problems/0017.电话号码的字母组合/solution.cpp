class Solution {
private:
    vector<string> result;
    string path;
    const string letterMap[10] = {
    "", // 0
    "", // 1
    "abc", // 2
    "def", // 3
    "ghi", // 4
    "jkl", // 5
    "mno", // 6
    "pqrs", // 7
    "tuv", // 8
    "wxyz", // 9
    };
public:
    vector<string> letterCombinations(string digits) {
            result.clear();
            path.clear();
            if (digits.size() == 0) return result;
            backTracking(digits, 0);
            return result;
    }

    void backTracking(string digits, int index) {
        if (path.size() == digits.size()) {
            result.push_back(path);
            return;
        }
        int digitNum = digits[index] - '0';
        string letters = letterMap[digitNum];
        for (int i = 0; i < letters.size(); i++) {
            path.push_back(letters[i]);
            backTracking(digits, index + 1);
            path.pop_back();
        }
    }
};