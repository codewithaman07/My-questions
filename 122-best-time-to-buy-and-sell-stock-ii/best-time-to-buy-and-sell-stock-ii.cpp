class Solution {
public:
    int solve(vector<int>& prices, int i, int n, int buy, vector<vector<int>>& dp) {
        if (i == n) return 0; 
        if (dp[i][buy] != -1) return dp[i][buy]; 
        int p, np;
        if (buy == 0) {
            p = solve(prices, i+1, n, 1, dp) - prices[i];
            np = solve(prices, i+1, n, 0, dp); 
        } 
        else {
            p = solve(prices, i+1, n, 0, dp) + prices[i]; 
            np = solve(prices, i+1, n, 1, dp); 
        }
        return dp[i][buy] = max(p, np);
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(prices, 0, n, 0, dp); 
    }
};
