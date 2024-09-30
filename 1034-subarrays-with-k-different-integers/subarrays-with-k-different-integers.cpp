class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
    int cnt[20001] = {}, res = 0, sz = nums.size();
    for (int l = 0, m = 0, r = 0; r < sz; ++r) {
        if (++cnt[nums[r]] == 1)
            if (--k < 0) {
                cnt[nums[m++]] = 0;
                l = m;
            }
        if (k <= 0) {
            while (cnt[nums[m]] > 1)
                --cnt[nums[m++]];
            res += m - l + 1;   
        }
    }
    return res;
    } 






    
    // int solve(vector<int>&nums, int k){
    //     int l = 0, r = 0, n = nums.size(), cnt = 0;
    //     map<int,int>mp;
    //     while(r<n){
    //         mp[nums[r]]++;
    //         while(mp.size()>k){
    //             if(--mp[nums[l]] == 0) mp.erase(nums[l]);
    //             l++;
    //         }
    //         cnt+=(r-l+1);
    //         r++;
    //     }
    //     return cnt;
    // }
    // int subarraysWithKDistinct(vector<int>& nums, int k) {
    //     return solve(nums,k)- solve(nums, k-1);
    // }
};