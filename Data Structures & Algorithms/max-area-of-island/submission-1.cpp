class Solution {
   public:
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};

    bool check(int i, int j, int n, int m) {
        if (i < 0 || i >= n) return false;
        if (j < 0 || j >= m) return false;

        return true;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                queue<pair<int, int>> q;
                int curr = 0;

                if (!vis[i][j] && grid[i][j] == 1) {
                    vis[i][j] = 1;
                    q.push({i, j});

                    while (!q.empty()) {
                        curr++;
                        auto [row, col] = q.front();

                        q.pop();
                        for (int k = 0; k < 4; k++) {
                            int newrow = row + dx[k];
                            int newcol = col + dy[k];

                            if (check(newrow, newcol, n, m) && !vis[newrow][newcol] &&
                                grid[newrow][newcol] == 1) {
                                vis[newrow][newcol]=1;
                                q.push({newrow, newcol});
                            }
                        }
                    }
                }
                ans = max(ans, curr);
            }
        }
        return ans;
    }
};
