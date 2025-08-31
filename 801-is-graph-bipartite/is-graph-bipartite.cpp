class Solution {
public:
    bool dfs(int i, int col, vector<int>&vis, vector<vector<int>>&graph){
        vis[i] = col;
        for(auto nbr : graph[i]){
            if(vis[nbr] == -1){
                if(dfs(nbr, !col, vis, graph) == false) return false;
            }
            else if(vis[nbr] == col) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>vis(n, -1);
        for(int i = 0; i<n; i++){
            if(vis[i] != -1) continue;
            if(dfs(i,0,vis,graph) == false) return false;
        }
        return true;
    }
};