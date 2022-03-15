class Solution {
private:
    vector<int> path;
    vector<vector<int>> res;
public:
    void backTracking(const vector<int>& nums, int startIndex) {
        res.push_back(path);
        if (startIndex >= nums.size()) return;
        for (int i = startIndex; i < nums.size(); i++) {
            if (i > startIndex && nums[i] == nums[i - 1]) {
                continue;
            }
            path.push_back(nums[i]);
            backTracking(nums, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        path.clear();
        res.clear();
        sort(nums.begin(), nums.end());
        backTracking(nums, 0);
        return res;
    }
};