class Solution {
public:
    #define ll long long
    bool fun(int mid, vector<vector<pair<int,int>>>&adj, vector<bool>&online, ll k){
        int n = online.size();
        priority_queue<pair<ll,ll>, vector<pair<ll,ll>>,greater<>>pq;
        vector<ll>dist(n,LLONG_MAX);
        dist[0] = 0;
        pq.push({0,0});
        while(!pq.empty()){
            auto [cost, node] = pq.top();
            pq.pop();
            if(cost > dist[node]) continue;
            for(auto [v, wt] : adj[node]){
                if(!online[v] || wt < mid) continue;
                if(dist[v] > wt+dist[node]){
                    dist[v] = wt+dist[node];
                    pq.push({dist[v], v});
                }
            }
        }
        return dist[n-1]<=k;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int,int>>>adj(n);
        int maxi = INT_MIN;
        for(auto e : edges){
            int u = e[0], v = e[1], wt = e[2];
            adj[u].push_back({v,wt});
            maxi = max(maxi,wt);
        }
        int l = 0, r = maxi, ans = -1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(fun(mid,adj, online, k)){
                ans = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
        return ans;
    }
};