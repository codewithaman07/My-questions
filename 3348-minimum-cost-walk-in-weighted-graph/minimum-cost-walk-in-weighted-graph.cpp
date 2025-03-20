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
        parent.resize(n);
        vector<int>cost(n);
        for(int i = 0; i<n; i++){
            parent[i] = i;
            cost[i] = -1;
        }
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            int pu = find(u);
            int pv = find(v);
            if(pu != pv){
                Union(pu, pv);
                cost[pu] &= cost[pv];
            }
            cost[pu]&=w;
        }
        vector<int>ans;
        for(auto q : query){
            int a = q[0];
            int b = q[1];
            int pa = find(a);
            int pb = find(b);
            if(a == b) ans.push_back(0);
            else if(pa != pb) ans.push_back(-1);
            else ans.push_back(cost[parent[a]]);
        }
        return ans;
    }
};