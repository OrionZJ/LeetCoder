class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> res_set;
        unordered_set<int> nums(nums1.begin(), nums1.end());
        for (int num : nums2) {
            if (nums.find(num) != nums.end()) {
                res_set.insert(num);
            }
        }
        return vector<int>(res_set.begin(), res_set.end());
    }
};