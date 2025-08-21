class Solution {
public:
    #define ll long long
    long long incremovableSubarrayCount(vector<int>& nums) {
        ll n = nums.size(), ans = 0;
        ll l = 0, r = n-1;
        while(l<n-1 && nums[l] < nums[l+1]) l++;
        if(l == n-1) return n*(n+1)/2;
        while(r>0 && nums[r] > nums[r-1]) r--;
        ans+=(l+1+n-r+1);
        int j = r;
        for(int i = 0; i<=l; i++){
            while(j<n && nums[i] >= nums[j]) j++;
            ans+=(n-j);
        }
        return ans;
    }
};