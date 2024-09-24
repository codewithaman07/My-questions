class Solution {
public:
    int uniquePaths(int n, int m) {
        vector<vector<int>>dp(n, vector<int>(m,0));
        dp[0][0] = 1;
        for(int i = 1; i<n; i++) dp[i][0] = dp[i-1][0];
        for(int j = 1; j<m; j++) dp[0][j] = dp[0][j-1];
        for(int i = 1; i<n; i++){
            for(int j = 1; j<m; j++){
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[n-1][m-1];
    }
};

// class Solution {
// public:
//     int solve(int i, int j, vector<vector<int>>&dp){
//         if(i == 0 && j == 0) return 1;
//         if(i<0 || j<0) return 0;
//         if(dp[i][j] != -1) return dp[i][j];
//         int up = solve(i-1, j, dp);
//         int left = solve(i, j-1, dp);
//         return dp[i][j] = left+up;
//     }
//     int uniquePaths(int n, int m) {
//         vector<vector<int>>dp(n, vector<int>(m,-1));
//         return solve(n-1,m-1,dp);
//     }
// };