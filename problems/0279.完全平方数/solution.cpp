class Solution {
public:
    int numSquares(int n) {
        vector<int> square(1, 1);
        vector<int> dp(n + 1, INT_MAX);    // dp[j]：和为j的完全平方数的最少数量为dp[j]
        for (int i = 2; i * i <= n; i++) square.push_back(i * i);
        dp[0] = 0;
        for (int i = 0; i < square.size(); i++) {
            for (int j = square[i]; j <= n; j++) {
                dp[j] = min(dp[j], dp[j - square[i]] + 1);
            }
        }
        return dp[n];
    }
};