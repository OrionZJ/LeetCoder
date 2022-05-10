class Solution {
private:
    vector<vector<string>> res;
    bool ifValid(int row, int col, const vector<string> &map) {
        for (int i = 0; i < row; i++) {
            if (map[i][col] == 'Q') return false;
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (map[i][j] == 'Q') return false;
        }
        for (int i = row - 1, j = col + 1; i>= 0 && j < map[i].size(); i--, j++) {
            if (map[i][j] == 'Q') return false;
        }
        return true;
    }

    void backTracking(int row, vector<string> &map, int n) {
        if (row == n) {
            res.push_back(map);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (ifValid(row, i, map)) {
                map[row][i] = 'Q';
                backTracking(row + 1, map, n);
                map[row][i] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        res.clear();
        vector<string> map(n, string(n, '.'));
        backTracking(0, map, n);
        return res;
    }
};