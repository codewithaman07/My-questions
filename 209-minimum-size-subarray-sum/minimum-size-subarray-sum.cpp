class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, ans = INT_MAX, sum = 0, n = nums.size();
        if(target == 0) return 0;
        for(int r = 0; r<n; r++){
            sum+=nums[r];
            while(sum >= target){
                ans = min(ans, r-l+1);
                sum-=nums[l++];
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};