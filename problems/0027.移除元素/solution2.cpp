class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        int slow_p = 0;
        for (int fast_p = 0; fast_p < size; fast_p++) {
            if (val != nums[fast_p]) {
                nums[slow_p++] = nums[fast_p];
            }
        }
        return slow_p;
    }
};
