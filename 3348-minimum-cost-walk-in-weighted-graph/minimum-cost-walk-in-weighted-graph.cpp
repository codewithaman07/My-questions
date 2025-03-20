class Solution {
public:
    vector<int>parent;
    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    void Union(int x, int y){
        parent[y] = x;
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<int>cost(n,-1);
        parent.resize(n);
        for(int i = 0; i<n; i++) parent[i] = i;
        for(auto &e : edges){
            int u = e[0], v = e[1], w = e[2];
            int pu = find(u), pv = find(v);
            if(pu != pv){
                Union(pu,pv);
                cost[pu] &= cost[pv];
            }
            cost[pu]&=w;
        }
        vector<int>ans;
        for(auto &q : query){
            int u = q[0], v = q[1];
            int pu = find(u), pv = find(v);
            if(u == v) ans.push_back(0);
            else if(pu != pv) ans.push_back(-1);
            else ans.push_back(cost[parent[u]]);
        }
        return ans;
    }
};