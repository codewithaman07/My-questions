class Solution {
public:
    #define ll long long
    long long maximumTripletValue(vector<int>& nums) {
        ll n = nums.size(), maxi = 0, diff = 0, ans = 0;
        for(int i = 0; i<n; i++){
            ans = max(ans, 1ll*(diff)*nums[i]);
            maxi = max(maxi, 1ll*nums[i]);
            diff = max(maxi-nums[i], diff);
        }
        return ans;
    }
};