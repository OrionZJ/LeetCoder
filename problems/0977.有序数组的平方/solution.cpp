#include <math.h>
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left_p = 0;
        int right_p = nums.size() - 1;
        int insertPos = nums.size() - 1;
        vector<int> powNums(nums.size() );
        while (insertPos >= 0) {        //取平方数组两边较大值赋给新数组尾部
            if (pow(nums[left_p],2) >= pow(nums[right_p],2) ) {
                powNums[insertPos--] = pow(nums[left_p++],2);       
            }
            else {
                powNums[insertPos--] = pow(nums[right_p--],2);
            }
        }
        return powNums;
    }
};
