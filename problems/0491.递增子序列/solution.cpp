class Solution {
private:
    vector<int> path;
    vector<vector<int>> res; 
public:
    void backTracking(const vector<int>& nums, int startIndex) {
       if (path.size() > 1) res.push_back(path);
       unordered_set<int> uset;
       for (int i = startIndex; i < nums.size(); i++) {
            if (!path.empty() && nums[i] < path.back() || uset.find(nums[i]) != uset.end())
                continue;
            uset.insert(nums[i]);
            path.push_back(nums[i]);
            backTracking(nums, i + 1);
            path.pop_back();
       }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        path.clear();
        res.clear();
        backTracking(nums, 0);
        return res;
    }
};