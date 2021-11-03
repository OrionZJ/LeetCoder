class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            if (nums[i] == val) {
                switchElement(nums,i,size - 1);
                size--;
                i--;
            }
        }
        return size;
    }

    void switchElement(vector<int>& nums, int pos_1, int pos_2) {
        int a;
        a = nums[pos_1];
        nums[pos_1] = nums[pos_2];
        nums[pos_2] = a;
    }
};
