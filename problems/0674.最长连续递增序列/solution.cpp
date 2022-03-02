class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        vector<int> dp(nums.size(), 1);    // // dp[i]以第i个元素结尾的最长连续递增子序列长度
        int maxLength = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) dp[i] = dp[i - 1] + 1;
            maxLength = max(maxLength, dp[i]);
        }
        return maxLength;
    }
};