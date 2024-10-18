class Solution {
public:
    int solve(vector<int>&nums, int i, int n, int curr, int maxi){
        if(i == n) return curr == maxi ? 1 : 0;
        int x = solve(nums, i+1, n, curr, maxi);
        int y = solve(nums, i+1, n, curr|nums[i], maxi);
        return x+y;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int ans = 0, maxi = 0, n = nums.size();
        for(int i = 0; i<n; i++) maxi |= nums[i];
        return solve(nums, 0, n, 0, maxi);
    }
};