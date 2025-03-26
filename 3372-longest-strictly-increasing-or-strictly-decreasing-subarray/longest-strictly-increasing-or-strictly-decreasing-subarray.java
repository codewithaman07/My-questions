class Solution {
    public int longestMonotonicSubarray(int[] nums) {
        int n = nums.length, cnt = 1, maxi = 1;
        for(int i = 0; i<n-1; i++){
            if(nums[i]<nums[i+1]) cnt++;
            else cnt = 1;
            maxi = Math.max(cnt,maxi);
        }
        cnt = 1;
        for(int i = 0; i<n-1; i++){
            if(nums[i]>nums[i+1]) cnt++;
            else cnt = 1;
            maxi = Math.max(cnt,maxi);
        }
        return maxi;
    }
}