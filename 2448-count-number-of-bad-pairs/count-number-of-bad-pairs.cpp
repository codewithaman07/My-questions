class Solution {
public:
    #define ll long long 
    ll fun(ll n){
        return (n*(n-1)/2);
    }
    long long countBadPairs(vector<int>& nums) {
        ll ans = 0, n = nums.size();
        unordered_map<ll,ll>mp;
        for(ll i = 0; i<n; i++){
            ll num = nums[i];
            mp[num-i]++;
        }
        for(auto &[x,y] : mp){
            if(y>1) ans+=fun(y);
        }
        return fun(n)-ans;
    }
};

// class Solution {
// public:
//     #define ll long long 
//     long long countBadPairs(vector<int>& nums) {
//         ll ans = 0;
//         int n = nums.size();
//         vector<int>temp;
//         for(int i = 0; i<n; i++){
//             temp.push_back(nums[i]-i);
//         }
//         sort(temp.begin(),temp.end());
//         for(int i = 0; i<n; i++){
//             ll t = temp[i];
//             int idx = upper_bound(temp.begin(), temp.end(), t) - temp.begin();
//             ans+=(n-idx);
//         }
//         return ans;
//     }
// };