class Solution {
public:
    #define ll long long
    int countPaths(int n, vector<vector<int>>& roads) {
        int M = 1e9+7;
        vector<vector<pair<ll,ll>>>adj(n);
        for(auto e : roads){
            int u = e[0], v = e[1], wt = e[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>>pq;
        vector<ll>dist(n,1e14), ways(n,0);
        pq.push({0,0});
        dist[0] = 0;
        ways[0] = 1;
        while(!pq.empty()){
            ll dis = pq.top().first;
            ll node = pq.top().second;
            pq.pop();
            for(auto it : adj[node]){
                ll nbr = it.first;
                ll wt = it.second;
                if(dist[nbr]>wt+dis){
                    ways[nbr] = ways[node];
                    dist[nbr] = wt+dis;
                    pq.push({dist[nbr], nbr});
                }
                else if(dist[nbr] == wt+dis){
                    ways[nbr] = (ways[nbr]+ways[node])%M;
                }
            }     
        }
        return ways[n-1];
    }
};