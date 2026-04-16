#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

int n, m;
vector<vector<int>> g;
vector<vector<int>> dist;

using state = pair<int, int>;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

vector<state> neighbors(state node) {
    vector<state> neigh;
    for (int k = 0; k < 4; k++) {
        int x = node.F + dx[k];
        int y = node.S + dy[k];
        if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 1) {
            neigh.push_back({x, y});
        }
    }
    return neigh;
}

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        g = grid;
        n = g.size();
        m = g[0].size();
        dist.assign(n, vector<int>(m, -1));
        queue<state> q;
        int freshCount = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] == 2) {
                    dist[i][j] = 0;
                    q.push({i, j});
                } else if (g[i][j] == 1) {
                    freshCount++;
                }
            }
        }

        if (freshCount == 0) return 0;

        int minutes = 0;
        while (!q.empty()) {
            state node = q.front();
            q.pop();
            for (state v : neighbors(node)) {
                if (dist[v.F][v.S] == -1) {
                    dist[v.F][v.S] = dist[node.F][node.S] + 1;
                    minutes = max(minutes, dist[v.F][v.S]);
                    freshCount--;
                    q.push(v);
                }
            }
        }

        return (freshCount == 0) ? minutes : -1;
    }
};