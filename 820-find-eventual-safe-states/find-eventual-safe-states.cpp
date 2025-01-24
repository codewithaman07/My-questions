class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>>adj(n);
        vector<int>degree(n,0);
        for(int i = 0; i<n; i++){
            for(auto it : graph[i]){
                adj[it].push_back(i);
                degree[i]++;
            }
        }
        queue<int>q;
        for(int i = 0; i<n; i++){
            if(!degree[i]) q.push(i);
        }
        vector<int>ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it : adj[node]){
                degree[it]--;
                if(!degree[it]) q.push(it);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};