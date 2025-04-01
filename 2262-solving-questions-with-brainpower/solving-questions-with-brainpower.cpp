class Solution {
public:
    #define ll long long
    ll solve(int i, vector<vector<int>>&grid, vector<ll>&dp){
        int n = grid.size();
        if(i>=n) return 0;
        if(dp[i] != -1) return dp[i];
        ll np = solve(i+1,grid,dp);
        ll p = grid[i][0]+solve(i+1+grid[i][1], grid,dp);
        return dp[i] = max(p,np);
    }
    long long mostPoints(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<ll>dp(n+1,-1);
        return solve(0,grid,dp);
    }
};

// class Solution {
// public:
//     #define ll long long
//     long long mostPoints(vector<vector<int>>& grid) {
//         int n = grid.size();
//         vector<ll>dp(n+1,0);
//         dp[n-1] = grid[n-1][0];
//         for(int i = n-2; i>=0; i--){
//             ll np = dp[i+1];
//             ll temp = i+1+grid[i][1];
//             ll p = grid[i][0]+(temp<n ? dp[temp] : 0);
//             dp[i] = max(p,np);
//         }
//         return dp[0];
//     }
// };