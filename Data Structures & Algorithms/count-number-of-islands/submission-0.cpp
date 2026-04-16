class Solution {
public:
    int n, m;
    vector<vector<int>> vis;

    bool is_valid(int x, int y, vector<vector<char>>& grid) {
        return (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '1');
    }

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    void dfs(int r, int c, vector<vector<char>>& grid) {
        vis[r][c] = 1;
        for (int k = 0; k < 4; k++) {
            int nx = r + dx[k];
            int ny = c + dy[k];
            if (is_valid(nx, ny, grid) && !vis[nx][ny]) {
                dfs(nx, ny, grid);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        if (n == 0) return 0;
        m = grid[0].size();
        vis.assign(n, vector<int>(m, 0));
        int island = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    island++;
                    dfs(i, j, grid);
                }
            }
        }
        return island;
    }
};