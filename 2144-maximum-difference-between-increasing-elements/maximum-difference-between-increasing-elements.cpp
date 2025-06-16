class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans = -1, n = nums.size(), mini = INT_MAX;
        for(int i = 0; i<n; i++){
            mini = min(mini, nums[i]);
            if(nums[i]>mini) ans = max(ans,nums[i]-mini);
        }
        return ans;
    }
};