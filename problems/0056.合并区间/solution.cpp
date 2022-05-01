class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> res;
        int beg = intervals[0][0];
        int end = intervals[0][1];
        for (int i = 1; i <= intervals.size(); i++) {
            if (i < intervals.size() && intervals[i][0] <= end) {
                end = max(end, intervals[i][1]);
                beg = min(beg, intervals[i][0]);
                continue;
            }
            res.push_back(vector<int> {beg, end});
            if (i < intervals.size()) {
                beg = max(intervals[i][0], beg);
                end = max(intervals[i][1], end);
            }
        }
        return res;
    }
};