class Solution {
   public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    bool check(int i, int j, int n, int m) {
        if (i < 0 || i >= n) return false;
        if (j < 0 || j >= m) return false;

        return true;
    }

    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& adj) {
      
        int n = grid.size();
        int m = grid[0].size();

        adj[i][j] = 1;

        for (int p = 0; p < 4; p++) {

            int ni = i + dx[p];
            int nj = j + dy[p];

            if (check(ni, nj, n, m) && grid[ni][nj] == '1' && !adj[ni][nj]) {
                dfs(ni, nj, grid, adj);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int ans = 0;
        vector<vector<int>> adj(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !adj[i][j]) {
                    dfs(i, j, grid, adj);
                    cout<<i<<" "<<j<<endl;
                    ans++;
                }
            }
        }
        return ans;
    }
};
