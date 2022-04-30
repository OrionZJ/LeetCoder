class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> rec(26, -1);
        for (int i = 0; i < s.size(); i++) {
            rec[s[i] - 'a'] = i;
        }
        vector<int> res;
        int cnt = 0;
        int end = rec[s[0] - 'a'];
        for (int i = 0; i < s.size(); i++) {
            end = max(rec[s[i] - 'a'], end);
            cnt++;
            if (i == end) {
                res.push_back(cnt);
                cnt = 0;
            }
        }
        return res;
    }
};