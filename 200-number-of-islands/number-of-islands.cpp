class Solution {
public:
    void solve(vector<vector<char>>&grid, vector<vector<bool>>&vis, int &n, int &m, int i, int j){
        if(i>=n || j>=m || i<0 || j<0 || vis[i][j] || grid[i][j] == '0') return;
        vis[i][j] = 1;
        solve(grid,vis,n,m,i+1,j);
        solve(grid,vis,n,m,i-1,j);
        solve(grid,vis,n,m,i,j+1);
        solve(grid,vis,n,m,i,j-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0, n = grid.size(), m = grid[0].size();
        vector<vector<bool>>vis(n, vector<bool>(m,0));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(vis[i][j] || grid[i][j] == '0') continue;
                solve(grid,vis,n,m,i,j);
                ans++;
            }
        }
        return ans;
    }
};