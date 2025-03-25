class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto e : flights){
            int u = e[0], v = e[1], wt = e[2];
            adj[u].push_back({v,wt});
        }
        queue<pair<int,pair<int,int>>>q;
        vector<int>dist(n,1e9);
        dist[src] = 0;
        q.push({0,{src,0}});
        while(!q.empty()){
            auto temp = q.front();
            int cnt = temp.first;
            int node = temp.second.first;
            int cost = temp.second.second;
            q.pop();
            if(cnt>k) continue;
            for(auto it : adj[node]){
                int nbr = it.first;
                int wt = it.second;
                if(dist[nbr]>wt+cost && cnt<=k){
                    dist[nbr] = wt+cost;
                    q.push({cnt+1,{nbr,dist[nbr]}});
                }
            }
        }
        return (dist[dst] == 1e9) ? -1 : dist[dst];
    }
};