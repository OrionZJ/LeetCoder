class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() == 0 || k == 0) return 0;
        vector<int> dp(2 * k + 1);
        for (int i = 1; i < dp.size(); i += 2) {
            dp[i - 1] = 0;
            dp[i] = -prices[0];
        }
        for (int i = 1; i < prices.size(); i++) {
            for (int j = 1; j < dp.size(); j += 2) {
                dp[j] = max(dp[j], dp[j - 1] - prices[i]);
                dp[j + 1] = max(dp[j + 1], dp[j] + prices[i]);
            }
        }
        return dp[dp.size() - 1];
    }
};