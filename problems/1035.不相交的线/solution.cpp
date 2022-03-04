class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
        // dp[i][j]：长度为[0, i - 1]的字符串nums1与长度为[0, j - 1]的字符串nums2的最长公共子序列为dp[i][j]
        for (int i = 1; i <= nums1.size(); i++) {
            for (int j = 1; j <= nums2.size(); j++) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp.back().back();
    }
};