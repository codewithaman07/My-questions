class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1, 0);
        dp[0] = nums[0];
        if(n==1) return nums[0];
        dp[1] = max(nums[0],nums[1]);
        for(int i = 2; i<n; i++){
            dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
        }
        return dp[n-1];
    }
};

// class Solution {
// public:
//     int solve(int i, vector<int>&nums, vector<int>&dp){
//         if(i<0) return 0;
//         if(dp[i] != -1) return dp[i];
//         int prev = solve(i-1,nums,dp);
//         int prev2 = solve(i-2, nums,dp)+nums[i];
//         return dp[i] = max(prev, prev2);
//     }
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         vector<int>dp(n+1, -1);
//         return solve(n-1,nums,dp);
//     }
// };