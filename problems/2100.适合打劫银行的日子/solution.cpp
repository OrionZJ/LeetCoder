class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        vector<int> lMax(security.size(), 0);
        vector<int> rMax(security.size(), 0);
        vector<int> ret;
        for (int i = 1; i < lMax.size(); i++) {
            if (security[i - 1] >= security[i]) {
                lMax[i] = lMax[i - 1] + 1;
            }
        }
        for (int i = security.size() - 2; i >= 0; i--) {
            if (security[i] <= security[i + 1]) {
                rMax[i] = rMax[i + 1] + 1;
            }
        }
        for (int i = 0; i < security.size(); i++) {
            if (lMax[i] >= time && rMax[i] >= time) {
                ret.push_back(i);
            }
        }
        return ret;
    }
};