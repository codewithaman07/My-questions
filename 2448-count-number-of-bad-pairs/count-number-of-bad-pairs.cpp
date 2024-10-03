class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long ans = 0, n = nums.size();
        map<long long , long long >mp;
        for(int i = 0; i<n; i++){
            mp[nums[i]-i]++;
        }
        for(auto &it : mp){
            long long cnt = it.second;
            if(cnt > 1){
                ans+=(cnt*(cnt-1)/2);
            }
        }
        return (n*(n-1)/2)-ans;
    }
};