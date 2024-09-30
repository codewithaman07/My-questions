class Solution {
public:
    int solve(vector<int>&prices, int i, int buy, int fee, vector<vector<int>>&dp){
        int n = prices.size();
        if(i == n) return 0;
        if(dp[i][buy] != -1) return dp[i][buy];
        int p, np;
        if(buy == 0){
            p = solve(prices, i+1, 1, fee, dp) - prices[i];
            np = solve(prices, i+1, 0, fee, dp);
        }
        else{
            p = solve(prices, i+1, 0, fee, dp) + prices[i] - fee;
            np = solve(prices, i+1, 1, fee, dp);
        }
        return dp[i][buy] = max(p,np);
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>>dp(n, vector<int>(2,-1));
        return solve(prices, 0, 0, fee, dp);
    }
};