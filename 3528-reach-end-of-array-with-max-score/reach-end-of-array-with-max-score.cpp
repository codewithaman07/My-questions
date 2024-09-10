class Solution {
public:
#define ll long long
    long long findMaximumScore(vector<int>& nums) {
        ll maxi = nums[0], n = nums.size(), ans = 0;
        for(int i = 1; i<n; i++){
            ans+=maxi;
            maxi = max(maxi, nums[i]*1ll);
        }
        return ans;
    }
};