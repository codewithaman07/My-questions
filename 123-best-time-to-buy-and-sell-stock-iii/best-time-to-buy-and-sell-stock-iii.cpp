class Solution {
public:
    int solve(vector<int>&prices, int i, int buy, int k, vector<vector<vector<int>>>&dp){
        int n = prices.size();
        if(i == n || k == 0) return 0;
        if(dp[i][buy][k] != -1) return dp[i][buy][k];
        int p, np;
        if(buy == 0){
            p = solve(prices, i+1, 1, k-1, dp) - prices[i];
            np = solve(prices, i+1, 0, k, dp);
        }
        else{
            p = solve(prices, i+1, 0, k-1, dp) + prices[i];
            np = solve(prices, i+1, 1, k, dp);
        }
        return dp[i][buy][k] = max(p,np);
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0) return 0;
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(2, vector<int>(5, -1)));
        return solve(prices, 0, 0, 4, dp);
    }
};