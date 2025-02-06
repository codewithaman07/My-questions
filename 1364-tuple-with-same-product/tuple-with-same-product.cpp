class Solution {
public:
    #define ll long long 
    ll fun(ll n){
        return (n)*(n-1)/2;
    }
    int tupleSameProduct(vector<int>& nums) {
        int ans = 0, n = nums.size();
        unordered_map<ll,ll>mp;
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                ll prod = (ll)nums[i]*nums[j];
                mp[prod]++;
            }
        }
        for(auto &[x,y] : mp){
            ll num = fun(y);
            ans+= num*8;
        }
        return ans;
    }
};