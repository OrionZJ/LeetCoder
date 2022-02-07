class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        // 尽量让石头分成重量相同的两堆，相撞之后剩下的石头最小
        int sum = culSum(stones);
        int half = sum / 2;
        vector<int> dp(half + 1, 0);
        // dp[j]表示容量为j的背包，最多可以背dp[j]重的石头
        for (int i = 0; i < stones.size(); i++) {
            for (int j = half; j >= stones[i]; j--) {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }
        return sum - 2 * dp[half];
    }

    int culSum(vector<int> a) {
        int sum = 0;
        for (int i = 0; i < a.size(); i++) {
            sum += a[i];
        }
        return sum;
    }
};