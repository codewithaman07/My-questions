class Solution {
public:
    #define ll long long 
    int specialTriplets(vector<int>& nums) {
        long long  n = nums.size(), ans = 0, mod = 1e9+7;
        unordered_map<ll,ll>l,r;
        l[nums[0]]++;
        for(int i = 1; i<n; i++) r[nums[i]]++;
        for(int i = 1; i<n-1; i++){
            r[nums[i]]--;
            ll  a = (l[nums[i]*2])%mod;
            ll b = (r[nums[i]*2])%mod;
            ans = (ans + (a*b)%mod)%mod;
            // cout<<"a,b,num :"<<a<<" "<<b<<" "<<nums[i]<<endl;
            l[nums[i]]++;
        }
        return (int)ans;
    }
};