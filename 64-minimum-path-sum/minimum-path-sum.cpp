class Solution {
public:
    int solve(int i, int j, vector<vector<int>>&grid, vector<vector<int>>&dp){
        if(i<0 || j<0) return INT_MAX;
        if(i == 0 && j == 0) return grid[0][0];
        if(dp[i][j] != -1) return dp[i][j];
        int a = solve(i-1, j, grid, dp);
        int b = solve(i, j-1, grid, dp);
        return dp[i][j] = grid[i][j]+min(a,b);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        return solve(n-1,m-1, grid, dp);
    }
};