class Solution {
public:
    int solve(vector<int>&nums, int k){
        int l = 0, r = 0, n = nums.size(), cnt = 0, sum = 0;
        while(r<n){
            sum+=(nums[r]&1);
            while(sum>k){
                sum-=(nums[l]&1);
                l++;
            }
            if(sum<=k){
                cnt+=(r-l+1);
            }
            r++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
    }
};