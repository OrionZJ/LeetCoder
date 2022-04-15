class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        int ind = -1;
        for (int i = 0; nums[i] < 0 && i < nums.size(); i++) {
            if (k <= 0) break;
            nums[i] = -nums[i];
            sum += nums[i];
            k--;
            ind = i;
        }
        if (k > 0) {
            if (k % 2 != 0) {
                if (ind + 1 < nums.size()) {
                    if (ind >= 0 && nums[ind] < nums[ind + 1]) {
                        sum = sum - 2 * nums[ind];
                        nums[ind] = -nums[ind];
                    } else nums[ind + 1] = -nums[ind + 1];
                } else {
                    sum = sum - 2 * nums[ind];
                    nums[ind] = -nums[ind];
                }
            }
        }
        for (int i = ind + 1; i < nums.size(); i++) {
                sum += nums[i];
            }
        return sum;
    }
};