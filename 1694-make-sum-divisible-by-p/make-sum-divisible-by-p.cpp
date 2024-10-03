class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int total = 0;
        for(int &num : nums) total = (total+num)%p;
        if(total == 0) return 0;
        unordered_map<int,int>mp;
        mp[0] = -1;
        int sum = 0, mini = n;
        for(int i = 0; i<n; i++){
            sum = (sum+nums[i])%p;
            int rem = sum%p;
            if(rem < 0) rem+=p;
            int req = (rem-total)%p;
            if(req<0) req+=p;
            if(mp.find(req) != mp.end()){
                mini = min(mini, i-mp[req]);
            }
            mp[rem] = i;
        }
        return mini < n ? mini : -1;
    }
};