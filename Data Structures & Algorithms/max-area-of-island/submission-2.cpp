class Solution {
public:

    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,-1,0,1};
    vector<vector<int>> neighbours(int i, int j, vector<vector<int>>& grid){
        vector<vector<int>> neighbour;
        for(int k=0;k<4;k++){
            int x = i+dx[k];
            int y = j+dy[k];
            if(x>=0&&x<grid.size()&&y>=0&&y<grid[0].size()&&grid[x][y]==1){
                neighbour.push_back({x,y});
            }
        }
        return neighbour;
    }

    int ans = 0;
    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis){
        vis[i][j] = 1;
        int count = 1;
        for(auto v:neighbours(i,j,grid)){
            if(!vis[v[0]][v[1]]){
                count += dfs(v[0],v[1],grid,vis);
            }
        }
        return count;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(),0));
        int maxArea = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    maxArea = max(maxArea,dfs(i,j,grid,vis));
                }
            }
        }
        return maxArea;
    }
};
