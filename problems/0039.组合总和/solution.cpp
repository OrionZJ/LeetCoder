class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        result.clear();
        path.clear();
        sort(candidates.begin(), candidates.end());
        backTracking(candidates, target, 0, 0);
        return result;
    }

    void backTracking(vector<int> candidates, int target, int index, int sum) {
        if (sum == target) {
            result.push_back(path);
            return;
        }
        for (int i = index; i < candidates.size() && sum + candidates[i] <= target; i++) {
            path.push_back(candidates[i]);
            sum += candidates[i];
            backTracking(candidates, target, i, sum);
            sum -= candidates[i];
            path.pop_back();
        }
    }
};