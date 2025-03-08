class Solution {
public:
    int solve(int i, int j, int k, vector<vector<vector<int>>>&dp, vector<vector<int>>&coins){
        if(i<0 || j<0) return INT_MIN;
        if(i == 0 && j == 0){
            if(k>0 && coins[i][j]<0) return 0;
            else return coins[i][j];
        }
        if(dp[i][j][k] != INT_MIN) return dp[i][j][k];
        int p = INT_MIN, np = INT_MIN;
        p = coins[i][j]+max(solve(i,j-1,k,dp,coins), solve(i-1,j,k,dp,coins));
        if(k>0 && coins[i][j]<0){
            np = max(solve(i,j-1,k-1,dp,coins), solve(i-1,j,k-1,dp,coins));
        }
        return dp[i][j][k] = max(p,np);
    }
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size(), m = coins[0].size();
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(m+1, vector<int>(3,INT_MIN)));
        return solve(n-1,m-1,2, dp, coins);
    }
};