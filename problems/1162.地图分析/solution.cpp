class Solution {
public:
    static constexpr int INF = int(1E6);
    struct cor {
        int x, y;
    };

    int maxDistance(vector<vector<int>>& grid) {
        int x_dir[4] = {1, 0, -1, 0};
        int y_dir[4] = {0, 1, 0, -1};
        queue<cor> que;
        vector<vector<int>> dis(grid.size(), vector<int>(grid.size(), INF));
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j]) {
                    que.push({i, j});
                    dis[i][j] = 0;
                }
            }
        }

        while (!que.empty()) {
            auto a = que.front();
            que.pop();
            for (int i = 0; i < 4; ++i) {
                int new_x = a.x + x_dir[i];
                int new_y = a.y + y_dir[i];
                if (new_x < 0 || new_y < 0 || new_x >= grid.size() || new_y >= grid.size()) continue;
                if (dis[new_x][new_y] > dis[a.x][a.y] + 1) {
                    dis[new_x][new_y] = dis[a.x][a.y] + 1;
                    que.push({new_x, new_y});
                }
            }
        }
        int res = -1;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid.size(); ++j) {
                if (!grid[i][j]) {
                    res = max(res, dis[i][j]);
                }
            }
        }
        return (res == INF ? -1 : res);
    }
};