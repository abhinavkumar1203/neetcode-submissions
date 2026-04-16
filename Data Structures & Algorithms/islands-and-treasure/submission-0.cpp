#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using state = pair<int,int>;
const int INF = 2147483647;
#define F first
#define S second

class Solution {
public:
    int n, m;
    vector<vector<int>>* arr_ptr;

    bool is_valid(int x, int y) {
        if (x >= 0 && x < n && y >= 0 && y < m && (*arr_ptr)[x][y] != -1) {
            return true;
        }
        return false;
    }

    int dx[4] = {0, 1, -1, 0};
    int dy[4] = {1, 0, 0, -1};

    void islandsAndTreasure(vector<vector<int>>& grid) {
        n = grid.size();
        if (n == 0) return;
        m = grid[0].size();
        arr_ptr = &grid;
        
        queue<state> q;

        // MULTI-SOURCE INITIALIZATION
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            state node = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nx = node.F + dx[k];
                int ny = node.S + dy[k];
                
                if (is_valid(nx, ny) && grid[nx][ny] == INF) {
                    grid[nx][ny] = grid[node.F][node.S] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
};