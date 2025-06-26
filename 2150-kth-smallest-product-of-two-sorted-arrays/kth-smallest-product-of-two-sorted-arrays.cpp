class Solution {
public:
    #define ll long long
    ll solve(vector<int>&nums, vector<int>&nums2, ll mid){
        ll cnt = 0, n = nums2.size();
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]>=0){
                ll l = 0, r = n-1, temp = -1;
                while(l<=r){
                    ll m = l+(r-l)/2;
                    ll prod = 1ll*(nums[i])*nums2[m];
                    if(prod<=mid){
                        temp = m;
                        l = m+1;
                    }
                    else r = m-1;
                }
                cnt+=(temp+1);
            }
            else{
                ll l = 0, r = n-1, temp = n;
                while(l<=r){
                    ll m = l+(r-l)/2;
                    ll prod = 1ll*(nums[i])*nums2[m];
                    if(prod<=mid){
                        temp = m;
                        r = m-1;
                    }
                    else l = m+1;
                }
                cnt+=(n-temp);
            }
        }
        return cnt;
    }
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        ll l = -1e10, r = 1e10, ans = 0;
        while(l<=r){
            ll m = l+(r-l)/2;
            ll num = solve(nums1, nums2, m);
            if(num>=k){
                r = m-1;
                ans = m;
            }
            else l = m+1;
        }
        return ans;
    }
};