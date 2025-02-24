class Solution {
public:
    #define ll long long
    bool fun(vector<int>&nums, int &k, ll &n, ll m){
        ll cnt = 0;
        for(int i = 0; i<n; i++){
            cnt+=(m/nums[i]);
        }
        return cnt>=k;
    }
    long long minimumTime(vector<int>& nums, int k) {
        ll l = 0, r = 1e14, n = nums.size();
        while(l<r){
            ll m = l+(r-l)/2;
            if(fun(nums,k,n,m)) r = m;
            else l = m+1;
        }
        return l;
    }
};