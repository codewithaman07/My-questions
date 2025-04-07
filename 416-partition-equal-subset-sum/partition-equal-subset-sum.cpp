class Solution {
public:
    bool solve(int i, int sum, int t, vector<int>&nums, vector<vector<int>>&dp){
        int n = nums.size();
        if(sum == t) return 1;
        if(i>=n || sum>t) return 0;
        if(dp[i][sum] != -1) return dp[i][sum];
        return dp[i][sum] = (solve(i+1,sum+nums[i], t, nums, dp) || solve(i+1,sum,t,nums, dp));
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum&1) return 0;
        int t = sum/2, n = nums.size();
        vector<vector<int>>dp(n+1, vector<int>(t+1,-1));
        return solve(0,0,t,nums, dp);
    }
};

// class Solution {
// public:
//     bool solve(int i, int sum, int t, vector<int>&nums){
//         int n = nums.size();
//         if(sum == t) return 1;
//         if(i>=n) return 0;
//         return solve(i+1,sum+nums[i], t, nums) || solve(i+1,sum,t,nums);
//     }
//     bool canPartition(vector<int>& nums) {
//         int sum = accumulate(nums.begin(), nums.end(), 0);
//         if(sum&1) return 0;
//         int t = sum/2;
//         return solve(0,0,t,nums);
//     }
// };