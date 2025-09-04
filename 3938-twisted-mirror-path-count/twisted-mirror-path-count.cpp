class Solution {
public:
    const int mod = 1e9+7;
    #define ll long long
    int solve(int i, int j, vector<vector<int>>&grid, vector<vector<vector<int>>>&dp, int dir){
        if(i<0 || j<0) return 0;
        if(i == 0 && j == 0) return 1;
        if(dp[i][j][dir] != -1) return dp[i][j][dir];
        if(grid[i][j]){
            if(dir == 1) return dp[i][j][dir] = solve(i-1,j,grid,dp,0)%mod;
            else return dp[i][j][dir] = solve(i,j-1,grid,dp,1)%mod;
        }
        ll up = solve(i-1,j,grid,dp,0)%mod;
        ll left = solve(i,j-1,grid,dp,1)%mod;
        return dp[i][j][dir] = (left+up)%mod;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(m, vector<int>(3,-1)));
        return solve(n-1,m-1,grid,dp, 2)%mod;;
    }
};