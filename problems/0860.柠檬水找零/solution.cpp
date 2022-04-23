class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        if (bills[0] != 5) return false;
        vector<int> pocket(2, 0);
        for (int i = 0; i < bills.size(); i++) {
            if (bills[i] == 5) pocket[0]++;
            else if (bills[i] == 10) {
                pocket[1]++;
                if (pocket[0]) pocket[0] --;
                else return false;
            }
            else if (bills[i] == 20) {
                if (pocket[1] && pocket[0]) {
                    pocket[1]--;
                    pocket[0]--;
                }
                else if (pocket[0] >= 3) pocket[0] -= 3;
                else return false;
            }
        }
        return true;
    }
};