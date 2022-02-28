class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        vector<vector<int>> dp(2, vector<int>(5));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        dp[0][2] = 0;
        dp[0][3] = -prices[0];
        dp[0][4] = 0;
        for (int i = 1; i < prices.size(); i++) {
            dp[i % 2][0] = dp[(i - 1) % 2][0];
            dp[i % 2][1] = max(dp[(i - 1) % 2][0] - prices[i], dp[(i - 1) % 2][1]);
            dp[i % 2][2] = max(dp[(i - 1) % 2][1] + prices[i], dp[(i - 1) % 2][2]);
            dp[i % 2][3] = max(dp[(i - 1) % 2][2] - prices[i], dp[(i - 1) % 2][3]);
            dp[i % 2][4] = max(dp[(i - 1) % 2][3] + prices[i], dp[(i - 1) % 2][4]);
        }
        return dp[(prices.size() - 1)% 2][4];
    }
};