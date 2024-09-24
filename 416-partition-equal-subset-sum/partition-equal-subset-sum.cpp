class Solution {
public:
    bool solve(int i, int j, vector<int>&nums, vector<vector<int>>&dp){
        if(j == 0) return 1;
        if(i<0) return 0;
        if(i == 0 && j == nums[0]) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        bool np = solve(i-1, j, nums, dp);
        bool p = 0;
        if(nums[i]<=j){
            p = solve(i-1, j-nums[i], nums, dp);
        }
        return dp[i][j] = p || np;
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(),0);
        if(sum&1) return 0;
        int k = sum/2, n = nums.size();
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        return solve(n-1,k,nums,dp);






        // if(nums[0]<=k) dp[0][nums[0]] = 1;
        // for(int i = 0; i<n; i++) dp[i][0] = 1;
        // for(int i = 1; i<n; i++){
        //     for(int j = nums[0]; j<=k; j++){
        //         dp[i][j] = dp[i-1][j];
        //         if(nums[i]<=j) dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]];
        //     }
        // }
        // return dp[n-1][k];
    }
};