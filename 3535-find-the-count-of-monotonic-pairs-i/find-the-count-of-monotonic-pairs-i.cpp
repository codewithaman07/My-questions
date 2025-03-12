class Solution {
public:
    int dp[2001][51][51];
    const int M = 1e9+7;
    int solve(int i, int n, vector<int>&nums, int prev, int prev2){
        if(i>=n) return 1;
        if(dp[i][prev][prev2] != -1) return dp[i][prev][prev2];
        long long cnt = 0;
        for(int j = prev; j<=nums[i]; j++){
            if(nums[i]-j<=prev2){
                cnt = (cnt+solve(i+1,n,nums,j,nums[i]-j)%M)%M;
            }
        }
        return dp[i][prev][prev2] = cnt;
    }
    int countOfPairs(vector<int>& nums) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(0,n,nums,0,50);
    }
};