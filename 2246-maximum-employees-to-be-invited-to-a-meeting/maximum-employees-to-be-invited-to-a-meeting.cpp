class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<int>indegree(n,0), chain(n,0);
        vector<bool>vis(n,0);
        for(int &fav : favorite) indegree[fav]++;
        queue<int>q;
        for(int i = 0; i<n; i++){
            if(indegree[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            vis[node] = 1;
            int next = favorite[node];
            chain[next] = chain[node]+1;
            indegree[next]--;
            if(indegree[next] == 0) q.push(next);
        }
        int maxCycle = 0, chainLen = 0;
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                int curr = i, len = 0;
                while(!vis[curr]){
                    vis[curr] = 1;
                    len++;
                    curr = favorite[curr];
                }
                if(len == 2) chainLen += 2 + chain[i] + chain[favorite[i]];
                else maxCycle = max(maxCycle, len);
            }
        }
        return max(maxCycle, chainLen);
    }
};