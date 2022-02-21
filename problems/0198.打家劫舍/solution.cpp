class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size());
        // dp[i]：考虑下标i（包括i）以内的房屋，最多可以偷窃的金额为dp[i]。
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[nums.size() - 1];
    }
};