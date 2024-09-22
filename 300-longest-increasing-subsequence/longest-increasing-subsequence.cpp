class Solution {
public:
    int solve(int idx, int prev, vector<int>&nums, vector<vector<int>>&dp){
        int n = nums.size();
        if(idx == n){
            return 0;
        }
        if(dp[idx][prev+1] != -1) return dp[idx][prev+1];
        int np = 0 + solve(idx+1, prev, nums, dp);
        int p = 0;
        if(prev == -1 || nums[prev] < nums[idx]){
            p = 1+solve(idx+1, idx, nums, dp);
        }
        return dp[idx][prev+1] = max(p,np);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n, vector<int>(n+1,-1));
        return solve(0,-1,nums,dp);
    }
};