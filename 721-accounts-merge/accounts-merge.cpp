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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DSU ds(n);
        map<string,int>mp;
        for(int i = 0; i<n; i++){
            for(int j = 1; j<accounts[i].size(); j++){
                string mail = accounts[i][j];
                if(mp.find(mail) == mp.end()) mp[mail] = i;
                else ds.unions(i,mp[mail]);
            }
        }
        vector<string>merge[n];
        for(auto [x,y] : mp){
            int py = ds.find(y);
            merge[py].push_back(x);
        }
        vector<vector<string>>ans;
        for(int i = 0; i<n; i++){
            if(merge[i].size() == 0) continue;
            sort(merge[i].begin(),merge[i].end());
            merge[i].insert(merge[i].begin(), accounts[i][0]);
            ans.push_back(merge[i]);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};