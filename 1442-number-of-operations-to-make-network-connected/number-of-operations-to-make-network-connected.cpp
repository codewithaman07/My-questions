class DSU{
    public:
    vector<int>parent,size;
    DSU(int n){
        parent.resize(n);
        size.resize(n,1);
        for(int i = 0; i<n; i++){
            parent[i] = i;
        }
    }
    int find(int u){
        if(u == parent[u]) return u;
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
    int makeConnected(int n, vector<vector<int>>& edges) {
        DSU ds(n);
        int cnt = 0;
        for(auto e : edges){
            int u = e[0], v = e[1];
            if(ds.find(u) == ds.find(v)) cnt++;
            else ds.unions(u,v);
        }
        for (int i = 0; i < n; i++) {
            ds.parent[i] = ds.find(i);
        }
        unordered_set<int>st(ds.parent.begin(), ds.parent.end());
        int num = st.size();
        // cout<<st.size()<<endl;
        // cout<<cnt<<endl;
        // for(int num : ds.parent) cout<<num<<" ";
        if(num-1>cnt) return -1;
        return num-1;
    }
};