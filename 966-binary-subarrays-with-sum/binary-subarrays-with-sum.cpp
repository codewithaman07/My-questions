class Solution {
public:
    int solve(vector<int>&nums, int k){
        if(k<0) return 0; 
        int l = 0, r = 0, n = nums.size(), ans = 0, sum = 0;
        while(r<n){
            sum+=nums[r];
            while(sum>k){
                sum-=nums[l];
                l++;
            }
            if(sum<=k){
                ans = ans+(r-l+1);
            }
            r++;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return solve(nums,goal) - solve(nums,goal-1);
    }
};