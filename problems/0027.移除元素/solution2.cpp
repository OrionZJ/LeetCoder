class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        int slow_p = 0;
        for (int fast_p = 0; fast_p < size; fast_p++) {
            if (val != nums[fast_p]) {      
                nums[slow_p++] = nums[fast_p];      //如果快指针没指向待删除元素，将快指针所指的值赋值给慢指针所指处，慢指针右移
            }                                       //如果快指针指向待删除元素，快指针右移，后续慢指针指向该元素时，待删除元素被覆盖
        }
        return slow_p;      //慢指针数值恰好为数组大小
    }
};
