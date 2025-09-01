class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto &e : edges){
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,2*w});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>>pq;
        vector<int>dist(n, 1e9);
        pq.push({0,0});
        dist[0] = 0;
        while(!pq.empty()){
            int node = pq.top().second;
            int cost = pq.top().first;
            pq.pop();
            for(auto &nbr : adj[node]){
                int v = nbr.first;
                int wt = nbr.second;
                if(cost+wt < dist[v]){
                    dist[v] = cost+wt;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist[n-1] == 1e9 ? -1 : dist[n-1];
    }
};