class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        return max(robRange(nums, 0), robRange(nums, 1));
        // 情况一：考虑包含首元素，不包含尾元素
        // 情况二：考虑包含尾元素，不包含首元素
    }
    
    int robRange(vector<int> nums, int start) {
        vector<int> dp(nums.size() - 1);
        dp[0] = nums[start];
        dp[1] = max(nums[start + 1], nums[start]);
        for (int i = 2; i < dp.size(); i++) {
            dp[i] = max(dp[i - 2] + nums[start + i], dp[i - 1]);
        }
        return dp[dp.size() - 1];
    }
};