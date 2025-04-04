class DSU{
    public:
    vector<int>parent,size;
    DSU(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i = 0; i<n; i++) parent[i] = i;
    }
    int find(int u){
        if(parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }
    void unions(int u, int v){
        int pu = find(u), pv = find(v);
        if(pu == pv) return;
        if(size[pu]<size[pv]){
            parent[pu] = pv;
            size[pv]+=size[pu];
        }
        else{
            parent[pv] = pu;
            size[pu]+=size[pv];
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int mr = 0, mc = 0, n = stones.size();
        for(auto it : stones){
            mr = max(mr,it[0]);
            mc = max(mc,it[1]);
        }
        DSU ds(mr+mc+2);
        unordered_map<int,int>mp;
        for(auto it : stones){
            int nr = it[0], nc = mr+it[1]+1;
            ds.unions(nr,nc);
            mp[nr] = 1;
            mp[nc] = 1;
        }
        int cnt = 0;
        for(auto [x,y] : mp){
            if(ds.find(x) == x) cnt++;
        }
        return n-cnt;
    }
};