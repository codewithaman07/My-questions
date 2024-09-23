typedef long long ll;
class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        unordered_map<ll,ll>mp;
        ll ans = 0, n = nums.size();
        for(int i = 0; i<n; i++){
            int currgcd = __gcd(nums[i],k);
            for(auto it : mp){
                if((currgcd * it.first)%k == 0){
                    ans+=it.second;
                }
            }
            mp[currgcd]++;
        }
        return ans;
    }
};