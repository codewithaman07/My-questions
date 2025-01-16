class Solution {
public:
    #define ll long long
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<ll,ll>mp;
        int n = nums1.size(), m = nums2.size(), ans = 0;
        for(int i = 0; i<n; i++) mp[nums1[i]]+=m;
        for(int i = 0; i<m; i++) mp[nums2[i]]+=n;
        for(auto it : mp){
            ll num = it.first;
            ll freq = it.second;
            if(freq&1ll) ans^=num;
        }
        return ans;
    }
};