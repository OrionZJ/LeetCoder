class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ret = 0;
        for (int i = 0; i < prices.size() - 1; i++) {
            int prof = prices[i + 1] - prices[i];
            if (prof > 0) {
                ret += prof;
            }
        }
        return ret;
    }
};