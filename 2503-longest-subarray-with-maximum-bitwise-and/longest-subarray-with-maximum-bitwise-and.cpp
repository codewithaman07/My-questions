class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 1,temp = 0, n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        for(int i = 0; i<n; i++){
            if(nums[i] == maxi) temp++;
            else ans = max(ans,temp), temp = 0;
        }
        ans = max(ans,temp);
        return ans;
    }
};