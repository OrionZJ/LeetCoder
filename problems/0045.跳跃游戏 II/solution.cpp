class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int cover = 0;
        int preCover = -1;
        int step = 0;
        while (1) { 
            int i = preCover + 1;
            preCover = cover;
            for (; i <= preCover; i++) {
                cover = max(cover, nums[i] + i);
                if (cover >= nums.size() - 1) return step + 1;
            }
            if (cover > preCover) {
                step++;
            } else return 0;
        }
        return 0;
    }
};