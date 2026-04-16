class Solution {
public:
    using state = pair<int,int>;

    int n, m;
    vector<vector<int>> vis;

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    bool is_valid(int x, int y, vector<vector<int>>& grid) {
        return x >= 0 && x < n &&
               y >= 0 && y < m &&
               grid[x][y] == 1;
    }

    int dfs(int x, int y, vector<vector<int>>& grid) {
        vis[x][y] = 1;
        int cnt = 1;

        for(int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(is_valid(nx, ny, grid) && !vis[nx][ny]) {
                cnt += dfs(nx, ny, grid);
            }
        }
        return cnt;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        vis.assign(n, vector<int>(m, 0));

        int maxArea = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && !vis[i][j]) {
                    maxArea = max(maxArea, dfs(i, j, grid));
                }
            }
        }

        return maxArea;
    }
};
