class Solution {
public:
    #define ll long long
    long long maximumProduct(vector<int>& nums, int m) {
        int n = nums.size();
        ll ans = LLONG_MIN;
        vector<ll>mini(n,INT_MAX), maxi(n,INT_MIN);
        mini[n-1] = nums[n-1];
        maxi[n-1] = nums[n-1];
        for(int i = n-2; i>=0; i--){
            maxi[i] = max(nums[i]*1ll, maxi[i+1]);
            mini[i] = min(nums[i]*1ll, mini[i+1]);
        }
        if(m == 1){
            ans = max(maxi[0]*maxi[0], mini[0]*mini[0]);
            return ans;
        }
        
        for(int i = 0; i<n-m+1; i++){
            ans = max(ans, nums[i]*maxi[i+m-1]);
            ans = max(ans, nums[i]*mini[i+m-1]);
        }
        return ans;
    }
};