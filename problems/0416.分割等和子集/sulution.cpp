class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = culSum(nums);
        if (sum % 2 == 0) {
            int target = sum / 2;
            vector<int> dp(target + 1, 0);    // 背包总容量是j，最大可以凑成j的子集总和为dp[j]
            for (int i = 0; i < nums.size(); i++) {
                for (int j = target; j >= nums[i]; j--) {
                    dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
                }
            }
            if (dp[target] == target) return true;
        }
        return false;
    }

    int culSum(vector<int> nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) sum += nums[i];
        return sum;
    }
};