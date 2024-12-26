class Solution {
public:
    int solve(vector<int>&arr, int target){
        int n = arr.size();
        vector<vector<int>>dp(n, vector<int>(target+1, 0));
        if(arr[0] == 0) dp[0][0] = 2;
        else dp[0][0] = 1;
        if(arr[0] != 0 && arr[0]<=target) dp[0][arr[0]] = 1;
        for(int i = 1; i<n; i++){
            for(int j = 0; j<=target; j++){
                int np = dp[i-1][j];
                int p = 0;
                if(arr[i]<=j){
                    p = dp[i-1][j-arr[i]];
                }
                dp[i][j] = p+np;
            }
        }
        return dp[n-1][target];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum-target < 0 || (sum-target)%2 != 0){
            return 0;
        }
        return solve(nums, (sum-target)/2);
    }
};