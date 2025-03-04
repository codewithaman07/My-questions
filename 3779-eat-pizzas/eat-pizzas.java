class Solution {
    public long maxWeight(int[] nums) {
        long ans = 0;
        Arrays.sort(nums);
        int i = nums.length-1;
        int n = (i+1)/4;
        int odd = (n+1)/2, even = n/2;
        while(odd-- > 0) ans+=nums[i--];
        while(even-- > 0){
            ans+=nums[i-1];
            i-=2;
        }
        return ans;
    }
}