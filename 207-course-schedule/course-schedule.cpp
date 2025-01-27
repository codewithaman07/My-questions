class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int>indegree(n,0);
        vector<int>adj[n];
        for(auto it : prerequisites){
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        queue<int>q;
        int cnt = 0;
        for(int i = 0; i<n; i++){
            if(!indegree[i]) q.push(i);
        }
        while(!q.empty()){
            int num = q.front();
            q.pop();
            cnt++;
            for(int it : adj[num]){
                if(--indegree[it] == 0) q.push(it);
            }
        }
        return cnt == n;
    }
};