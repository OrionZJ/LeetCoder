class Solution {
public:
    int numDistinct(string s, string t) {
        // dp[i][j]：以i-1为结尾的s子序列中出现以j-1为结尾的t的个数为dp[i][j]
        vector<vector<uint64_t>> dp(t.size() + 1, vector<uint64_t>(s.size() + 1, 0));
        for (int i = 0; i <= s.size(); i++) dp[0][i] = 1;
        for (int i = 1; i <= t.size(); i++) {
            for (int j = 1; j <= s.size(); j++) {
                if (t[i - 1] != s[j - 1]) dp[i][j] = dp[i][j - 1];
                else dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
            }
        }
        return dp.back().back();
    }
};