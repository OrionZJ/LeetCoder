/** 滚动数组节省空间 **/
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++) dp[i] = 1;
        for (int j = 1; j < m; j++) {
            for (int i = 1; i < n; i++) {
                dp[i] += dp[i - 1];
            }
        }
        return dp[n - 1];
    }
};