class Solution {
public:
    int solve(vector<int>&nums, int i, int n, int curr, int maxi, vector<vector<int>>&dp){
        if(i == n) return curr == maxi ? 1 : 0;
        if(dp[i][curr] != -1) return dp[i][curr];
        int x = solve(nums, i+1, n, curr, maxi,dp);
        int y = solve(nums, i+1, n, curr|nums[i], maxi,dp);
        return dp[i][curr] = x+y;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int ans = 0, maxi = 0, n = nums.size();
        for(int i = 0; i<n; i++) maxi |= nums[i];
        vector<vector<int>>dp(n, vector<int>(maxi+1, -1));
        return solve(nums, 0, n, 0, maxi, dp);
    }
};