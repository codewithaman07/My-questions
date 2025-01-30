class FenwickTree{
    vector<long long>bit;
public:
    #define ll long long
    FenwickTree(int n) : bit(n+1,0){}
    void update(int idx, ll val){
        for(++idx; idx<bit.size(); idx+= idx & -idx) bit[idx]+=val;
    }
    ll query(int idx){
        ll sum = 0;
        for(++idx; idx>0; idx-= idx & -idx) sum+=bit[idx];
        return sum;
    }
};
class Solution {
public:
    #define ll long long
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int>pos(n);
        int idx = 0;
        for(int &num : nums2) pos[num] = idx++;
        FenwickTree bit1(n), bit2(n);
        ll ans = 0;
        for(int i = 0; i<n; i++){
            int idx = pos[nums1[i]];
            ll x = bit1.query(idx-1);
            ll c = bit2.query(idx-1);
            ans+=c;
            bit1.update(idx, 1);
            bit2.update(idx, x);
        }
        return ans;
    }
};