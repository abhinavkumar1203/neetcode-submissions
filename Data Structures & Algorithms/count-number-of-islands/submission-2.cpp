class Solution {
public:

bool isValid(int x, int y, vector<vector<char>>& grid){
    return (x>=0&&x<grid.size()&&y>=0&&y<grid[0].size() && grid[x][y]=='1');
}

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
vector<vector<int>> neighbours(int i, int j,vector<vector<char>>& grid){
    vector<vector<int>> neighbour;
    for(int k=0;k<4;k++){
        int x = i + dx[k];
        int y = j + dy[k];
        if(isValid(x,y,grid)){
            neighbour.push_back({x,y});
        }
    }
    return neighbour;
}
int island = 0;
    void dfs(int i, int j, vector<vector<char>>& grid,vector<vector<int>>& vis){
        //int node = grid[i][j];
        vis[i][j] = 1;
        for(auto v:neighbours(i,j,grid)){
            if(!vis[v[0]][v[1]]){
                dfs(v[0],v[1],grid,vis);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
    vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(),0));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    island += 1;
                    dfs(i,j,grid,vis);
                }
            }
        }
        return island;
    }
};
