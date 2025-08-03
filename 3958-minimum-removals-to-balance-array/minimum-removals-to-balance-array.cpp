class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int l = 0, ans = 0, n = nums.size();
        for(int r = 0; r<n; r++){
            while(1ll*nums[l]*k < nums[r]) l++;
            ans = max(ans, r-l+1);
        }
        return n-ans;
    }
};