class Solution {
public:

    vector<vector<int>> arr;
    vector<int> vis;   // 0 = unvisited, 1 = visiting, 2 = done
    vector<int> topo;
    bool isCycle = false;

    void dfs(int node){
        vis[node] = 1;   // visiting

        for(auto v : arr[node]){
            if(vis[v] == 0){
                dfs(v);
            }
            else if(vis[v] == 1){
                isCycle = true;   // back edge → cycle
            }
        }

        vis[node] = 2;   // finished
        topo.push_back(node);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        arr.assign(numCourses, {});
        vis.assign(numCourses, 0);
        topo.clear();
        isCycle = false;

        // b -> a
        for(auto &p : prerequisites){
            int a = p[0];
            int b = p[1];
            arr[b].push_back(a);
        }

        for(int i=0;i<numCourses;i++){
            if(vis[i] == 0){
                dfs(i);
            }
        }

        if(isCycle) return {};

        reverse(topo.begin(), topo.end());
        return topo;
    }
};
