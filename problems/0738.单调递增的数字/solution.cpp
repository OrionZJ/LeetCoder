class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        vector<int> nums;
        while (n) {
            nums.push_back(n % 10);
            n /= 10;
        }
        reverse(nums.begin(), nums.end());
        for (int i = nums.size() - 1; i > 0; i--) {
            if (nums[i - 1] > nums[i]) {
                nums[i - 1]--;
                for (int j = i; j < nums.size(); j++) {
                    nums[j] = 9;
                }
            }
        }
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            res += pow(10, nums.size() - i - 1) * nums[i];
        }
        return res;
    }
};