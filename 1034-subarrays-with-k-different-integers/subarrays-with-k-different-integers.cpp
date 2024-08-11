class Solution {
public:
    int solve(vector<int>&nums, int k){
        int l = 0, r = 0, n = nums.size(), cnt = 0;
        map<int,int>mp;
        while(r<n){
            mp[nums[r]]++;
            while(mp.size()>k){
                if(--mp[nums[l]] == 0) mp.erase(nums[l]);
                l++;
            }
            cnt+=(r-l+1);
            r++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums,k)- solve(nums, k-1);
    }
};