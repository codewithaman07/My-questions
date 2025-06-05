class DSU{
    public:
    vector<int>parent;
    DSU(int n){
        parent.resize(n+1);
        for(int i = 0; i<n; i++) parent[i] = i;
    }
    int find(int u){
        if(parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }
    void unions(int u, int v){
        int pu = find(u), pv = find(v);
        if(pu == pv) return;
        if(pu<pv) parent[pv] = pu;
        else parent[pu] = pv;
    }
};
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();
        DSU ds(26);
        for(int i = 0; i<n; i++){
            ds.unions(s1[i]-'a',s2[i]-'a');
        }
        string ans;
        for(char ch : baseStr){
            int parent = ds.find(ch-'a');
            ans+= (char)(parent+'a');
        }
        return ans;
    }
};