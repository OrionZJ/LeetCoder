// 01背包,物品的重量有两个维度
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        // dp[i][j]：最多有i个0和j个1的strs的最大子集的大小为dp[i][j]
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
        for (string str : strs) {
            int oneNum = 0, zeroNum = 0;
            for (char c : str) {
                if (c == '1') oneNum++;
                else zeroNum++;
            }
            for (int i = m; i >= zeroNum; i--) {
                for (int j = n; j >= oneNum; j--) {
                    dp[i][j] = max(dp[i][j], dp[i - zeroNum][j - oneNum] + 1);
                }
            }
        }
        return dp[m][n];
    }
};