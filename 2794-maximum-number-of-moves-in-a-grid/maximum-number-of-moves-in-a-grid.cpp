class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>&grid, vector<vector<int>>&dp){
        int n = grid.size(), m = grid[0].size();
        if(j == m-1) return 0;
        if(i<0 || j>=m || i>=n) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int dr[3][2] = {{-1,1}, {0,1}, {1,1}};
        int maxi = 0;
        for(auto &d : dr){
            int nx = i+d[0], ny = j+d[1];
            if(nx<0 || ny>=m || nx>=n) continue;
            if(grid[nx][ny]>grid[i][j]){
                int temp = 1+dfs(nx,ny,grid,dp);
                maxi = max(maxi, temp);
            }
        }
        return dp[i][j] = maxi;
    }
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>>dp(n, vector<int>(m,-1));
        int ans = 0;
        for(int i = 0; i<n; i++){
            ans = max(ans, dfs(i,0,grid,dp));
        }
        return ans;
    }
};