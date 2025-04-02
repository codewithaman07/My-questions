class Solution {
public:
#define ll long long
    long long maximumTripletValue(vector<int>& nums) {
        ll ans = 0, n = nums.size(), maxdiff = 0, maxi = 0;
        for(int num : nums){
            ans = max(ans, maxdiff*(num)); // 0 0 6 22 77
            maxi = max(maxi, 1ll*num); // 12 12 12 12 12
            maxdiff = max(maxdiff, maxi-num); // 0 6 11 11 11
        }
        return ans;
    }
};