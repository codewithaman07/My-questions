class Solution {
public:
    int maxArea(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1, lmax = nums[l], rmax = nums[r], ans = 0;
        while(l<r){
            lmax = max(lmax, nums[l]);
            rmax = max(rmax, nums[r]);
            ans = max((r-l)*min(lmax,rmax), ans);
            if(nums[l] < nums[r]) l++;
            else r--;
        }
        return ans;
    }
};