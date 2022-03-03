class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        // dp[i][j] ：以下标i - 1为结尾的A，和以下标j - 1为结尾的B，最长重复子数组长度为dp[i][j]
        // 此处转换为滚动数组
        vector<int> dp(nums2.size() + 1, 0);
        int maxLength = 0;
        for (int i = 1; i <= nums1.size(); i++) {
            for (int j = nums2.size(); j > 0; j--) {    // 从后向前遍历，避免重复覆盖
                if (nums2[j - 1] == nums1[i - 1]) {
                    dp[j] = dp[j - 1] + 1;
                } else dp[j] = 0;
                maxLength = max(maxLength, dp[j]);
            }
        }
        return maxLength;
    }
};