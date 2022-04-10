class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        //dp[i][0]第i个数作为山谷的wml，dp[i][1]第i个数作为山峰wml
        vector<vector<int>> dp(nums.size(), vector<int>(2, 1));
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] > nums[i]) dp[i][0] = max(dp[i][0], dp[j][1] + 1);
                if (nums[j] < nums[i]) dp[i][1] = max(dp[i][1], dp[j][0] + 1);
            }
        }
        return max(dp.back()[0], dp.back()[1]);
    }
};