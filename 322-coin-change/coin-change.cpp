class Solution {
public:
    int solve(int i, int j, vector<int>&nums, vector<vector<int>>&dp){
        if(j == 0) return 0;
        if(i<0) return INT_MAX-1;
        if(i == 0){
            if(j%nums[i] == 0) dp[i][j] = j/nums[i];
        }
        if(dp[i][j] != -1) return dp[i][j];
        int np = solve(i-1, j, nums,dp);
        int p = INT_MAX-1;
        if(nums[i]<=j){
            p = solve(i, j-nums[i], nums, dp)+1;
        }
        return dp[i][j] = min(p,np);
    }
    int coinChange(vector<int>& nums, int t) {
        int n = nums.size();
        vector<vector<int>>dp(n+1, vector<int>(t+1, -1));
        int ans = solve(n-1,t,nums,dp);
        return ans == INT_MAX-1 ? -1 : ans;
    }
};