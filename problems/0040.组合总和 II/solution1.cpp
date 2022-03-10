class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        result.clear();
        path.clear();
        vector<bool> used(candidates.size(), false);
        sort(candidates.begin(), candidates.end());
        backTracking(candidates, target, used, 0, 0);
        return result;
    }

    void backTracking(vector<int> candidates, int target, vector<bool> &used, int index, int sum) {
        if (sum == target) {
            result.push_back(path);
            return;
        }
        for (int i = index; i < candidates.size() && sum + candidates[i] <= target; i++) {
            if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false) continue;
            // used[i - 1] == true，说明同一树枝candidates[i - 1]使用过
            // used[i - 1] == false，说明同一树层candidates[i - 1]使用过
            // 要对同一树层使用过的元素进行跳过
            path.push_back(candidates[i]);
            used[i] = true;
            sum += candidates[i];
            backTracking(candidates, target, used, i + 1, sum);
            sum -= candidates[i];
            used[i] = false;
            path.pop_back();
        }
    }
};