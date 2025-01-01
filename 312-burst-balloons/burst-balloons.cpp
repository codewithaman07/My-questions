class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>>dp(n, vector<int>(n,0));
        for(int l = n-2; l>=1; l--){
            for(int r = l; r<=n-2; r++){
                for(int i = l; i<=r; i++){
                    int gain = nums[l-1]*nums[i]*nums[r+1];
                    int rem = dp[l][i-1]+dp[i+1][r];
                    dp[l][r] = max(gain+rem, dp[l][r]);
                }
            }
        }
        return dp[1][n-2];
    }
};