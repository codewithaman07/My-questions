class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<int>indegree(n,0);
        vector<int>ans(n,0);
        for(int i = 0; i<n; i++) ans[i] = i;
        vector<vector<int>>adj(n);
        for(auto it : richer){
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        queue<int>q;
        for(int i = 0; i<n; i++){
            if(indegree[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int nbr : adj[node]){
                if(quiet[ans[node]] < quiet[ans[nbr]]){
                    ans[nbr] = ans[node];
                }
                indegree[nbr]--;
                if(indegree[nbr] == 0) q.push(nbr);
            }
        }
        return ans;
    }
};