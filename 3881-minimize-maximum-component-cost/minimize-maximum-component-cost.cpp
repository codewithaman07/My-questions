class DSU{
public:
    vector<int>parent, rank;
    int comp;
    DSU(int n){
        parent.resize(n);
        rank.resize(n,0);
        comp = n;
        for(int i = 0; i<n; i++) parent[i] = i;
    }
    int find(int num){
        if(parent[num] == num) return parent[num];
        return parent[num] = find(parent[num]);
    }
    bool unite(int u, int v){
        int pu = find(u);
        int pv = find(v);
        if(pu == pv) return 0;
        comp--;
        if(rank[pu] < rank[pv]){
            parent[pu] = pv;
        }
        else if(rank[pu] > rank[pv]){
            parent[pv] = pu;
        }
        else{
            parent[pu] = pv;
            rank[pv]++;
        }
        return 1;
    }
    int compval(){
        return comp;
    }
};

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges, int k) {
        sort(edges.begin(),edges.end(),[&](vector<int>&e1, vector<int>&e2){
            return e1[2]<e2[2];
        });
        DSU ds(n);
        int comp = n;
        if(comp <= k) return 0;
        for(auto &e : edges){
            int u = e[0], v = e[1], wt = e[2];
            if(ds.unite(u,v)){
                if(ds.compval() == k) return wt;
            }
        }
        return -1;
    }
};