class Solution {
private:
    vector<int> path;
    vector<vector<int>> res;
public:
    void backTracing(const vector<int>& nums, vector<bool>& used) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i] == true) continue;
            path.push_back(nums[i]);
            used[i] = true;
            backTracing(nums, used);
            used[i] = false;
            path.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        path.clear();
        res.clear();
        vector<bool> used(nums.size(), false);
        backTracing(nums, used);
        return res;
    }
};