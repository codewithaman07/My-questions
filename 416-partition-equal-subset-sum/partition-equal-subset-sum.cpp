class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(),0);
        if(sum&1) return 0;
        int k = sum/2, n = nums.size();
        vector<vector<int>>dp(n,vector<int>(k+1,0));
        if(nums[0]<=k) dp[0][nums[0]] = 1;
        for(int i = 0; i<n; i++) dp[i][0] = 1;
        for(int i = 1; i<n; i++){
            for(int j = nums[0]; j<=k; j++){
                dp[i][j] = dp[i-1][j];
                if(nums[i]<=j) dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]];
            }
        }
        return dp[n-1][k];
    }
};