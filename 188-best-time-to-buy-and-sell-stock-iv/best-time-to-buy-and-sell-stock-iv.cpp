class Solution {
public:
    int solve(vector<int>&prices, int n, int i, int buy, int k, vector<vector<vector<int>>>&dp){
        if(i == n || k == 0) return 0;
        if(dp[i][buy][k] != -1) return dp[i][buy][k];
        int p,np;
        if(buy == 0){
            p = solve(prices, n, i+1, 1, k-1, dp) - prices[i];
            np = solve(prices, n, i+1, 0, k, dp);
        }
        else{
            p = solve(prices, n, i+1, 0, k-1, dp)+prices[i];
            np = solve(prices, n, i+1, 1, k, dp);
        }
        return dp[i][buy][k] = max(p,np);
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        k*=2;
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(2, vector<int>(2*k+1, -1)));
        return solve(prices, n, 0, 0, k, dp);
    }
};