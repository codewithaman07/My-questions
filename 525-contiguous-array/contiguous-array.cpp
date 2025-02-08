class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i<n; i++){
            if(nums[i] == 0) nums[i] = -1;
        }
        int maxi = 0, sum = 0;
        unordered_map<int,int>mp;
        mp[0] = -1;
        for(int i = 0; i<n; i++){
            sum+=nums[i];
            if(mp.count(sum)) maxi = max(maxi, i-mp[sum]);
            else mp[sum] = i;
        }
        return maxi;
    }
};