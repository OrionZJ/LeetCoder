class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();
        int cnt = 1;
        int preD = 0;
        int curD = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            curD = nums[i + 1] - nums[i];
            if ((preD <= 0 && curD > 0) || (preD >= 0 && curD < 0)) {
                cnt++;
                preD = curD;
            }
        }
        return cnt;
    }
};