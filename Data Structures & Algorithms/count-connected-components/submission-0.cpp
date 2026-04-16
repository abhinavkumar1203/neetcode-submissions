class Solution {
public:

    vector<vector<int>> arr;
    vector<int> vis;

    void dfs(int node){
        vis[node] = 1;
        for(auto v : arr[node]){
            if(!vis[v]){
                dfs(v);
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {

        arr.assign(n, {});
        vis.assign(n, 0);

        // build undirected graph
        for(auto &e : edges){
            int a = e[0];
            int b = e[1];
            arr[a].push_back(b);
            arr[b].push_back(a);
        }

        int concomp = 0;

        for(int i=0;i<n;i++){
            if(!vis[i]){
                concomp++;
                dfs(i);
            }
        }

        return concomp;
    }
};
