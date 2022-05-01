class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int minPri = prices[0];
        int prof = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < minPri) minPri = prices[i];
            if (prices[i] >= minPri && prices[i] <= minPri + fee) continue;
            if (prices[i] > minPri + fee) {
                prof += prices[i] - minPri - fee;
                minPri = prices[i] - fee;
            }
        }
        return prof;
    }
};