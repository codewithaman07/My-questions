class Solution {
public:
    int solve(int i, vector<int>&coins, int amount, int money, vector<vector<int>>&dp){
        int n = coins.size();
        if(money > amount) return 0;
        if(money == amount) return 1;
        if(i>=n) return 0;
        if(dp[i][money] != -1) return dp[i][money];
        int p = solve(i,coins,amount, coins[i]+money,dp);
        int np = solve(i+1,coins,amount, money,dp);
        return dp[i][money] = p+np;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n+1, vector<int>( amount+1, -1));
        return solve(0, coins, amount,0, dp);
    }
};

// class Solution {
// public:
//     int change(int target, vector<int>& arr) {
//         int n = arr.size();
//         vector<vector<int>>dp(n, vector<int>(target+1, 0));
//         for(int i = 0; i<=target; i++){
//             if(i%arr[0] == 0) dp[0][i] = 1;
//         }
//         for(int i = 1; i<n; i++){
//             for(int j = 0; j<=target; j++){
//                 int np = dp[i-1][j];
//                 int p = 0;
//                 if(arr[i]<=j){
//                     p = dp[i][j-arr[i]];
//                 }
//                 dp[i][j] = p+np;
//             }
//         }
//         return dp[n-1][target];
//     }
// };

// class Solution {
// public:
//     int solve(int i, vector<int>&coins, int amount, int money, vector<vector<int>>&dp){
//         int n = coins.size();
//         if(money > amount) return 0;
//         if(money == amount) return 1;
//         if(i>=n) return 0;
//         if(dp[i][money] != -1) return dp[i][money];
//         int p = solve(i,coins,amount, coins[i]+money,dp);
//         int np = solve(i+1,coins,amount, money,dp);
//         return dp[i][money] = p+np;
//     }
//     int change(int amount, vector<int>& coins) {
//         int n = coins.size();
//         vector<vector<int>>dp(n+1, vector<int>( amount+1, -1));
//         return solve(0, coins, amount,0, dp);
//     }
// };