class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto e : times){
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v,w});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        vector<int>dist(n+1,1e9);
        dist[k] = 0;
        pq.push({0,k});
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it : adj[node]){
                int nbr = it.first, wt = it.second;
                if(dist[nbr]>wt+dis){
                    dist[nbr] = wt+dis;
                    pq.push({dist[nbr], nbr});
                }
            }
        }
        int maxi = INT_MIN;
        for(int i = 1; i<=n; i++){
            if(dist[i] == 1e9) return -1;
            maxi = max(maxi,dist[i]);
        }
        return maxi;
    }
};