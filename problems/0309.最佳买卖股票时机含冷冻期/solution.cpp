class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        vector<vector<int>> dp(prices.size(), vector<int>(4, 0));
        dp[0][0] = -prices[0];    // 状态一：买入股票状态（今天买或已经持有）
        dp[0][1] = 0;    // 状态二：卖出股票，过了冷冻期，保持卖出状态
        dp[0][2] = 0;    // 状态三：今天卖出股票
        dp[0][3] = 0;    // 状态四：今天为冷冻期
        for (int i = 1; i < prices.size(); i++) {
            for (int j = 0; j < 4; j++) {
                dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][3]) - prices[i]);
                dp[i][1] = max(dp[i - 1][1], dp[i - 1][3]);
                dp[i][2] = dp[i - 1][0] + prices[i];
                dp[i][3] = dp[i - 1][2];
            }
        }
        return max(dp[(prices.size() - 1)][1], max(dp[(prices.size() - 1)][2], dp[(prices.size() - 1)][3]));
    }
};