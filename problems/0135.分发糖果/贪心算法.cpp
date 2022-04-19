class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> rec(ratings.size(), 1);
        int minNum = rec[0];
        int res = 0;
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i - 1]) rec[i] = rec[i - 1] + 1;
        }
        for (int i = rec.size() - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) rec[i] = max(rec[i], rec[i + 1] + 1);
        }

        for (int i : rec) {
            // i -= (minNum - 1);
            res += i;
        }
        return res;
    }
};