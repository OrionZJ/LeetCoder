class Solution {
public:
    int search(vector<int>& nums, int target) {
        int midPos = nums.size()/2;
        // cout << midPos;
        int result = compareMidPos(nums,midPos,nums.size()/2,target);
        // cout << result;
        return result;
    }

    int compareMidPos(vector<int>& nums, int &pos, int size, int target) {
        size = size / 2;
        if (target < nums[pos]) {
            if (pos-1 < 0 || target > nums[pos-1]) return -1;
            pos = pos - (size / 2 + 1); 
            compareMidPos(nums,pos,size,target);
        }
        if (target > nums[pos]) {
            if (pos + 1 >= nums.size() || target < nums[pos+1]) return -1;
            pos = pos + (size / 2 + 1);
            compareMidPos(nums,pos,size,target);
        }
        if (target == nums[pos]) return pos;
        else return -1;
    } 
};
