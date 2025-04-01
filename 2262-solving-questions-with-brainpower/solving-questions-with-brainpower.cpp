class Solution {
public:
    #define ll long long
    long long mostPoints(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<ll>dp(n+1,0);
        dp[n-1] = grid[n-1][0];
        for(int i = n-2; i>=0; i--){
            ll np = dp[i+1];
            ll temp = i+1+grid[i][1];
            ll p = grid[i][0]+(temp<n ? dp[temp] : 0);
            dp[i] = max(p,np);
        }
        return dp[0];
    }
};