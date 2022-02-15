class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 0; i <= target; i++) {    // 外层物品
            for (int j = 0; j < nums.size(); j++) {    // 内层背包
                if ( i - nums[j] >= 0 && dp[i] < INT_MAX - dp[i - nums[j]]) {
                    // C++测试用例有超过两个树相加超过int的数据
                    dp[i] += dp[i - nums[j]];
                }
            }
        }
        return dp[target];
    }
};