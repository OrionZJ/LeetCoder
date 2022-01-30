class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(obstacleGrid);
        if(obstacleGrid[0][0]) dp[0][0] = 0;
        else dp[0][0] = 1;
        for (int i = 1; i < obstacleGrid.size(); i++) {
            if (obstacleGrid[i][0] != 1) dp[i][0] = dp[i - 1][0];
            else dp[i][0] = 0;
        }
        for (int i = 1; i < obstacleGrid[0].size(); i++) {
            if (obstacleGrid[0][i] != 1) dp[0][i] = dp[0][i - 1];
            else dp[0][i] = 0;
        }
        for (int i = 1; i < obstacleGrid.size(); i++) {
            for (int j = 1; j < obstacleGrid[0].size(); j++) {
                recursion(i, j, dp, obstacleGrid);
            }
        }
        return dp[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
    }

    int recursion(int i, int j, vector<vector<int>> &dp, vector<vector<int>> obstacleGrid) {
        if (!obstacleGrid[i - 1][j] && !obstacleGrid[i][j -1] && !dp[i][j])
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        else if (obstacleGrid[i - 1][j] && !obstacleGrid[i][j -1] && !dp[i][j])
            dp[i][j] = dp[i][j - 1];
        else if (!obstacleGrid[i - 1][j] && obstacleGrid[i][j -1] && !dp[i][j])
            dp[i][j] = dp[i - 1][j];
        else
            dp[i][j] = 0;
        return dp[i][j];
    }
};