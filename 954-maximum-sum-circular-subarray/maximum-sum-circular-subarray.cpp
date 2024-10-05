class Solution {
public:

    int maxSubarraySumCircular(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        int mini = nums[0], maxi = nums[0], minsum = nums[0], maxsum = nums[0];
        for(int i = 1; i<n; i++){
            mini = min(nums[i], mini+nums[i]);
            minsum = min(minsum, mini);
            maxi = max(nums[i], maxi+nums[i]);
            maxsum = max(maxsum, maxi);
        }
        if(maxsum < 0) return maxsum;
        return max(maxsum, sum-minsum);
    }
};