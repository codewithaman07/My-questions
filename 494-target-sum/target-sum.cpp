class Solution {
public:
    int solve(int i, vector<int>&nums, int target, vector<vector<int>>&dp){
        int n = nums.size();
        if(i == 0) {
            if(target == 0 && nums[0] == 0) return 2;  // Both +0 and -0 count.
            if(target == 0 || target == nums[0]) return 1;
            return 0;
        }
        if(dp[i][target] != -1) return dp[i][target];
        int p = target-nums[i]>=0 ? solve(i-1, nums, target-nums[i], dp) : 0;
        int np = solve(i-1, nums, target, dp);
        return dp[i][target] = p+np;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum < abs(target) || (sum + target) % 2 != 0) return 0;
        vector<vector<int>>dp(n+1, vector<int>(sum+target+1,-1));
        return solve(n-1, nums, (sum+target)/2, dp);
    }
};