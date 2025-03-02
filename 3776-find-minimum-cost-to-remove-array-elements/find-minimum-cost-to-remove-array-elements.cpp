class Solution {
public:
    int solve(int prev, int i, vector<int>&nums, vector<vector<int>>&dp){
        int n = nums.size();
        if(i >= n) return nums[prev];
        if(i == n-1) return max(nums[prev], nums[i]);
        if(dp[i][prev] != -1) return dp[i][prev];
        int a = max(nums[i],nums[i+1])+solve(prev, i+2, nums, dp);
        int b = max(nums[prev], nums[i])+solve(i+1, i+2, nums,dp);
        int c = max(nums[prev], nums[i+1])+solve(i, i+2, nums, dp);
        return dp[i][prev] = min({a,b,c});
    }
    int minCost(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return solve(0,1,nums,dp);
    }
};