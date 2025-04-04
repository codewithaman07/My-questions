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
    bool valid(int nr, int nc, int n){
        return (nr>=0 && nr<n && nc>=0 && nc<n);
    }
    int dr[4] = {-1,0,1,0};
    int dc[4] = {0,-1,0,1};
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size(), ans = 0;
        int cnt = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                cnt+=grid[i][j];
            }
        }
        if(cnt == n*n) return cnt;
        DSU ds(n*n);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(!grid[i][j]) continue;
                for(int k = 0; k<4; k++){
                    int nr = i+dr[k];
                    int nc = j+dc[k];
                    if(valid(nr,nc,n) && grid[nr][nc]){
                        int x = i*n+j;
                        int y = nr*n+nc;
                        ds.unions(x,y);
                    }
                }
            }
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j]) continue;
                set<int>st;
                for(int k = 0; k<4; k++){
                    int nr = i+dr[k];
                    int nc = j+dc[k];
                    if(valid(nr,nc,n) && grid[nr][nc]){
                        st.insert(ds.find(nr*n+nc));
                    }
                }
                int sum = 0;
                for(auto num : st) sum+=ds.size[num];
                ans = max(ans,sum+1);
            }
        }
        // for(int i = 0; i<n*n; i++){
        //     ans = max(ans, ds.size[ds.find(i)]);
        // }
        return ans;
    }
};