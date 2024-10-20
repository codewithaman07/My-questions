class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>>dp(n, vector<int>(m, INT_MAX));
        dp[n-1][m-1] = max(1, 1-grid[n-1][m-1]);
        for(int i = n-2; i>=0; i--) dp[i][m-1] = max(1, dp[i+1][m-1]-grid[i][m-1]);
        for(int j = m-2; j>=0; j--) dp[n-1][j] = max(1, dp[n-1][j+1]-grid[n-1][j]);
        for(int i = n-2; i>=0; i--){
            for(int j = m-2; j>=0; j--){
                int right = max(1, dp[i][j+1]-grid[i][j]);
                int down = max(1, dp[i+1][j]-grid[i][j]);
                dp[i][j] = min(right,down);
            }
        }
        return dp[0][0];
    }
};