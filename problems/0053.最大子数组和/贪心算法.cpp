class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ret = INT_MIN;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            cnt += nums[i];
            ret = max(ret, cnt);
            if (cnt < 0) cnt = 0;
        }
        return ret;
    }
};