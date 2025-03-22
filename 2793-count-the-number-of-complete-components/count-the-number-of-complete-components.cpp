class Solution {
public:
    vector<int>parent;
    int find(int x){
        if(parent[x] == x) return x;
        return find(parent[x]);
    }
    void Union(int x, int y){
        parent[y] = x;
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        for(int i = 0; i<n; i++) parent[i] = i;
        for(auto &e : edges){
            int u = e[0], v = e[1];
            int pu = find(u), pv = find(v);
            if(pu != pv){
                Union(pu,pv);
            }
        }
        unordered_map<int,int>mp, mp2;
        int ans = 0;
        for(int i = 0; i<n; i++){
            int num = find(i);
            mp[num]++;
        }
        for(auto &e : edges){
            int num = find(e[0]);
            mp2[num]++;
        }
        for(auto &[x,y] : mp){
            if(mp2[x] == y*(y-1)/2) ans++;
        }
        return ans;
    }
};