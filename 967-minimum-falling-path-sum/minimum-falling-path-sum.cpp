class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>>dp(n, vector<int>(m,0));
        for(int j = 0; j<m; j++) dp[0][j] = grid[0][j];
        for(int i = 1; i<n; i++){
            for(int j = 0; j<m; j++){
                int lu = INT_MAX, ru = INT_MAX, up = INT_MAX;
                if(j-1>=0) lu = dp[i-1][j-1]+grid[i][j];
                if(j+1<m) ru = dp[i-1][j+1]+grid[i][j];
                up = dp[i-1][j]+grid[i][j]; 
                dp[i][j] = min({lu,up,ru});
            }
        }
        int mini = INT_MAX;
        for(int j = 0; j<m; j++) mini = min(mini, dp[n-1][j]);
        return mini;
    }
};