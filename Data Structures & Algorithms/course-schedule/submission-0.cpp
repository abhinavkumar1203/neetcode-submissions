class Solution {
public:
    vector<vector<int>> arr;
    vector<int> col;
    vector<int> parent;

    bool isCycle = 0;

    void dfs(int node, int par){
        parent[node] = par;
        col[node] = 2;

        for(auto v:arr[node]){
            if(col[v] == 1){
                dfs(v,node);
            }
            else if(col[v] == 2){
                isCycle = 1;
            }
        }
        col[node] = 3;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        arr.assign(numCourses, {});
        col.assign(numCourses, 1);
        parent.assign(numCourses, -1);
        isCycle = 0;

        for(auto &p : prerequisites){
            int a = p[0];
            int b = p[1];
            arr[b].push_back(a);
        }
        for(int i=0;i<numCourses;i++){
            if(col[i]==1){
                dfs(i,-1);
            }
        }
        return !isCycle;
    }
};
