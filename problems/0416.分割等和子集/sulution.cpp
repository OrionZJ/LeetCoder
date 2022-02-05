class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = sum(nums);
        if (sum % 2 == 0) {
            vector<int> dp(sum / 2, 0);
            for (int i = 0; i < nums.size(); i++) {
                for (int j = sum / 2; j >= nums[i]; j--)
            }
        }
    }

    int sum(vector<int> nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) sum += nums[i];
        return sum;
    }
};