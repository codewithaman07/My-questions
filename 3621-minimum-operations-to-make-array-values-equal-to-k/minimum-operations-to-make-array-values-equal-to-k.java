class Solution {
    public int minOperations(int[] nums, int k) {
        int n = nums.length;
        int mini = Integer.MAX_VALUE;
        for(int i = 0; i<n; i++){
            mini = Math.min(mini, nums[i]);
        }
        if(k>mini) return -1;
        HashMap<Integer, Integer>mp = new HashMap<>();
        for(int i = 0; i<n; i++){
            mp.put(nums[i], 1);
        }
        int ans = mp.size();
        if(mp.containsKey(k)) ans--;
        return ans;
    }
}