class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<unordered_set<int>>reachable(n);
        vector<vector<int>>adj(n);
        vector<int>indegree(n,0);
        for(auto &edge : prerequisites){
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            reachable[v].insert(u);
            indegree[v]++;
        }
        queue<int>q;
        for(int i = 0; i<n; i++){
            if(!indegree[i]) q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int &neighbor : adj[node]){
                reachable[neighbor].insert(reachable[node].begin(), reachable[node].end()); 
                if(--indegree[neighbor] == 0) q.push(neighbor);       
            }
        }
        vector<bool>ans;
        for(auto &query : queries){
            int u = query[0], v = query[1];
            ans.push_back(reachable[v].count(u));
        }
        return ans;
    }
};

// class Solution {
// public:
//     vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
//         unordered_map<int,unordered_set<int>>reachable;
//         for(auto & it : prerequisites){
//             reachable[it[1]].insert(it[0]);
//         }
//         for(int i = 0; i<n; i++){
//             for(int j = 0; j<n; j++){
//                 if(reachable[j].count(i)){
//                     reachable[j].insert(reachable[i].begin(), reachable[i].end());
//                 }
//             }
//         }
//         vector<bool>ans;
//         for(auto & query : queries){
//             ans.push_back(reachable[query[1]].count(query[0]));
//         }
//         return ans;
//     }
// };