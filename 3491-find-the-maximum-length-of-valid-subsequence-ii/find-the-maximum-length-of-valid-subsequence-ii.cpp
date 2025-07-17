class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        for(int &i : nums){
            i%=k;
        }
        vector<vector<int>>dp(n, vector<int>(k,0));
        vector<int>last(k,-1);
        int ans = 1;
        for(int i = 0; i<n; i++){
            for(int val = 0; val<k; val++){
                if(last[val] == -1) dp[i][val] = 1;
                else dp[i][val] = dp[last[val]][nums[i]]+1;
                ans = max(ans,dp[i][val]);
            }
            last[nums[i]] = i;
        }
        return ans;
    }
};