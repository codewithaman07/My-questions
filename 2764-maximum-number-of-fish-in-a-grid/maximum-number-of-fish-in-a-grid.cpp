class Solution {
public:
    int dr[4] = {0,0,1,-1};
    int dc[4] = {1,-1,0,0};
    bool valid(int nr, int nc, int n, int m){
        return (nr>=0 && nc>=0 && nr<n && nc<m);
    }
    void dfs(int i, int j, vector<vector<int>>&grid, vector<vector<bool>>&vis, int &sum){
        int n = grid.size(), m = grid[0].size();
        vis[i][j] = 1;
        sum+=grid[i][j];
        for(int d = 0; d<4; d++){
            int nr = i+dr[d];
            int nc = j+dc[d];
            if(valid(nr,nc,n,m) && grid[i][j] != 0 && !vis[nr][nc]){
                dfs(nr,nc,grid,vis,sum);
            }
        }
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>>vis(n, vector<bool>(m,0));
        int maxi = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!vis[i][j] && grid[i][j] != 0){
                    int sum = 0;
                    dfs(i,j,grid,vis,sum);
                    maxi = max(maxi, sum);
                }
            }
        }
        return maxi;
    }
};