class Solution {
public:
    bool dfs(unordered_map<int,vector<int>>&adj, int u, int v, vector<bool>&vis){
        vis[u] = 1;
        if(u == v) return 1;
        for(int &neighbor : adj[u]){
            if(vis[neighbor]) continue;
            if(dfs(adj,neighbor,v,vis)) return 1;
        }
        return 0;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        unordered_map<int,vector<int>>adj;
        for(int i = 0; i<n; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            vector<bool>vis(n+1,0);
            if(adj.count(u) && adj.count(v) && dfs(adj,u,v,vis)){
                return edges[i];
            }
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return {};
    }
};