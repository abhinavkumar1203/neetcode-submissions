class Solution {
public:

    #define F first
    #define S second

    using state = pair<int,int>;

    int n,m;
    vector<vector<int>> arr;
    vector<vector<int>> dist;

    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};

    vector<state> neighbors(state node){
        vector<state> neighs;
        for(int k=0;k<4;k++){
            int x = node.F + dx[k];
            int y = node.S + dy[k];
            if(x>=0 && x<n && y>=0 && y<m){
                neighs.push_back({x,y});
            }
        }
        return neighs;
    }

    void bfs(queue<state> q){
        while(!q.empty()){
            state node = q.front();
            q.pop();

            for(state v: neighbors(node)){
                if(dist[v.F][v.S] == -1 &&
                   arr[v.F][v.S] >= arr[node.F][node.S]){
                    dist[v.F][v.S] = dist[node.F][node.S] + 1;
                    q.push(v);
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        arr = heights;
        n = arr.size();
        m = arr[0].size();

        dist.assign(n, vector<int>(m,-1));
        queue<state> qP;

        for(int i=0;i<n;i++){
            dist[i][0] = 0;
            qP.push({i,0});
        }
        for(int j=0;j<m;j++){
            if(dist[0][j]==-1){
                dist[0][j]=0;
                qP.push({0,j});
            }
        }

        bfs(qP);
        vector<vector<int>> distP = dist;

        dist.assign(n, vector<int>(m,-1));
        queue<state> qA;

        for(int i=0;i<n;i++){
            dist[i][m-1] = 0;
            qA.push({i,m-1});
        }
        for(int j=0;j<m;j++){
            if(dist[n-1][j]==-1){
                dist[n-1][j]=0;
                qA.push({n-1,j});
            }
        }

        bfs(qA);
        vector<vector<int>> distA = dist;

        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(distP[i][j]!=-1 && distA[i][j]!=-1){
                    ans.push_back({i,j});
                }
            }
        }

        return ans;
    }
};
