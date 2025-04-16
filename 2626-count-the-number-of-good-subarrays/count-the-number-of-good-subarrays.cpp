class Solution {
public:
    #define ll long long
    long long countGood(vector<int>& nums, int k) {
        ll n = nums.size(), ans = 0, l = 0, cnt = 0;
        unordered_map<int,int>mp;
        for(int r = 0; r<n; r++){
            ll freq = mp[nums[r]];
            cnt-= (freq*(freq-1))/2;
            mp[nums[r]]++;
            cnt+=(freq*(freq+1))/2;
            while(cnt>=k){
                ans+=(n-r);
                ll freq = mp[nums[l]];
                cnt-=(freq*(freq-1))/2;
                mp[nums[l]]--;
                freq = mp[nums[l]];
                cnt+=(freq*(freq-1))/2;
                l++;
            }
        }
        return ans;
    }
};