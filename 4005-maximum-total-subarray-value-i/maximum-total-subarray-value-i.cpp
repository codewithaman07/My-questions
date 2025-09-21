class Solution {
public:
    #define ll long long
    long long maxTotalValue(vector<int>& nums, int k) {
        ll maxi = *max_element(nums.begin(), nums.end());
        ll mini = *min_element(nums.begin(), nums.end());
        ll ans = maxi-mini;
        return ans*k;
    }
};