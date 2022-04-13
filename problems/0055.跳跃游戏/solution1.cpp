class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1) return true;;
        vector<int> zeroIn;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) zeroIn.push_back(i);
        }
        if (zeroIn.size() == 0) return true;
        if (zeroIn[0] == 0) return false;
        for (int i = 0; i < zeroIn.size(); i++) {
            bool ifJump = false;
            int cnt = 1;
            if (zeroIn[i] == nums.size() - 1) break;
            for (int j = zeroIn[i] - 1; j >= 0; j--, cnt++) {
                if (nums[j] > cnt) {
                    ifJump = true;
                    break;
                }
            }
            if (ifJump == false) return false;
        }
        return true;
    }
};