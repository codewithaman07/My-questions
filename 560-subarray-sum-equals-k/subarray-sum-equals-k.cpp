class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0] = 1;
        int n = nums.size(), sum = 0, ans = 0;
        for(int i = 0; i<n; i++){
            sum+=nums[i];
            if(mp.count(sum-k)){
                ans+=mp[sum-k];
            }
            mp[sum]++;
        }
        return ans;
    }
};