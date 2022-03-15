class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;
public:
    void backTracking(const vector<int> &nums, int startIndex) {
        result.push_back(path);
        if (startIndex >= nums.size()) return;
        for (int i = startIndex; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backTracking(nums, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        path.clear();
        result.clear();
        backTracking(nums, 0);
        return result;
    }
};