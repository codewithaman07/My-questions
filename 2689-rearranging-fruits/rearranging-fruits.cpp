class Solution {
public:
    #define ll long long
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<ll,ll>mp;
        ll mini = LLONG_MAX, ans = 0;
        for(ll num : basket1){
            mini = min(mini, num);
            mp[num]++;
        }
        for(ll num : basket2){
            mini = min(mini, num);
            mp[num]--;
        }
        vector<int>nums;
        for(auto &[num, freq] : mp){
            freq = abs(freq);
            if(freq%2 == 1) return -1;
            else{
                for(int i = 0; i<freq/2; i++) nums.push_back(num);
            }
        }
        for(int i = 0; i<nums.size()/2; i++){
            ans = ans + min(1ll*nums[i], 2*mini);
            cout<<nums[i]<<" ";
        }
        return ans;
    }
};