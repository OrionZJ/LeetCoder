class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(int k, int targetSum, int startIndex) {
        if (targetSum < 0) return;
        if (path.size() == k) {
            if (targetSum == 0) result.push_back(path);
            return;
        }
        for (int i = startIndex; i <= 9 - (k - path.size()) + 1; i++) {
            targetSum -= i;
            path.push_back(i);
            backtracking(k, targetSum, i + 1);
            targetSum += i;
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        result.clear();
        path.clear();
        backtracking(k, n, 1);
        return result;      
    }
};