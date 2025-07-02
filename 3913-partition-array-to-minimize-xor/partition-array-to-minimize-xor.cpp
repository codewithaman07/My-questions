class Solution {
public:
    int solve(int i, int k, vector<int>&nums, vector<vector<int>>&dp){
        int n = nums.size();
        if(i==n) return (k == 0 ? 0 : INT_MAX);
        if(k==0) return INT_MAX;
        if(dp[i][k] != -1) return dp[i][k];
        int ans = INT_MAX, xorr = 0;
        for(int j = i; j<n; j++){
            xorr = xorr^nums[j];
            ans = min(ans, max(xorr, solve(j+1, k-1,nums,dp)));
        }
        return dp[i][k] = ans;
    }
    int minXor(vector<int>& nums, int k) {
        // i, k, 2d dp 
        int n = nums.size();
        vector<vector<int>>dp(n+1, vector<int>(k+1, -1));
        return solve(0,k,nums,dp);
    }
};