class Solution {
public:
    int numSquares(int n) {
        // dp[0] = 0; 
        // dp[i] = dp[i-x]+1 or dp[i]
        vector<int>dp(n+1, 1e9);
        dp[0] = 0;
        for(int i = 1; i<=n; i++){
            for(int j = 1; j*j<=i; j++){
                dp[i] = min(dp[i], dp[i-j*j]+1);
            }
        }
        return dp[n];
    }
};