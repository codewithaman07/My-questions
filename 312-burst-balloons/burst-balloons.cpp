class Solution {
public:
    int solve(int i, int j, vector<int>&arr, vector<vector<int>>&dp){
        if(i>j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int maxi = INT_MIN;
        for(int k = i; k<=j; k++){
            int coins = arr[i-1]*arr[k]*arr[j+1];
            int rem = solve(i,k-1,arr,dp)+solve(k+1,j,arr,dp);
            maxi = max(maxi, coins+rem);
        }
        return dp[i][j] = maxi;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>>dp(n+2, vector<int>(n+2, -1));
        return solve(1, n, nums, dp);
    }
};