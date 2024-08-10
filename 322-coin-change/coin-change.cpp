class Solution {
public:
    int coinChange(vector<int>& arr, int t) {
        int n = arr.size();
        vector<vector<int>>dp(n, vector<int>(t+1,0));
        for(int i = 0; i<=t; i++){
            if(i%arr[0] == 0) dp[0][i] = i/arr[0];
            else dp[0][i] = 1e9;
        }
        for(int i = 1; i<n; i++){
            for(int j = 0; j<=t; j++){
                int np = dp[i-1][j];
                int p = 1e9;
                if(arr[i]<=j) p = 1+dp[i][j-arr[i]];
                dp[i][j] = min(p,np);
            }
        }
        return dp[n-1][t] != 1e9 ? dp[n-1][t] : -1;  
    }
};