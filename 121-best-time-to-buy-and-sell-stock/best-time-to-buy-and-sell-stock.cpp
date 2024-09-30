class Solution {
public:
    int solve(vector<int>&prices, int i, int n, int buy, int k, vector<vector<vector<int>>>&dp){
        if(i == n || k == 0) return 0;
        if(dp[i][buy][k] != -1) return dp[i][buy][k];
        int p, np;
        if(buy == 0){
            p = solve(prices, i+1, n, 1, k-1, dp) - prices[i];
            np = solve(prices, i+1, n, 0, k, dp);
        }
        else{
            p = solve(prices, i+1, n, 0, k-1, dp) + prices[i];
            np = solve(prices, i+1, n, 1, k, dp);
        }
        return dp[i][buy][k] = max(p,np);
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(2, vector<int>(3,-1)));
        return solve(prices, 0, n, 0, 2, dp);
    }
};

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int mini = INT_MAX;
//         int maxi = 0;
//         int n = prices.size();
//         for(int i = 0; i<n; i++){
//             mini = min(mini,prices[i]);
//             maxi = max(maxi, prices[i]-mini);
//         }
//         return maxi;
//     }
// };