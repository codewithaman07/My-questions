class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int>dp(n,1), hash(n,1);
        for(int i = 0; i<n; i++){
            hash[i] = i;
            for(int prev = 0; prev<i; prev++){
                if(nums[i]%nums[prev] == 0 && dp[i] < 1+dp[prev]){
                    dp[i] = 1+dp[prev];
                    hash[i] = prev;
                }
            }
        }
        int ans = -1, last = -1;
        for(int i = 0; i<n; i++){
            if(dp[i] > ans){
                ans = dp[i];
                last = i;
            }
        }
        vector<int>temp;
        temp.push_back(nums[last]);
        while(last != hash[last]){
            last = hash[last];
            temp.push_back(nums[last]);
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }
};