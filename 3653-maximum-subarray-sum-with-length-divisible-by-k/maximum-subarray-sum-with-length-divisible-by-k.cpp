class Solution {
public:
    #define ll long long
    long long maxSubarraySum(vector<int>& nums, int k) {
        ll n = nums.size(), ans = LLONG_MIN;
        vector<ll>pre(n+1,0);
        for(int i = 0; i<n; i++){
            pre[i+1] = pre[i]+nums[i];
        }
        for(int i = 0; i<k; i++){
            ll sum = 0;
            for(int j = i; j+k<=n; j+=k){
                ll temp = pre[j+k]-pre[j];
                sum = max(temp, sum+temp);
                ans = max(ans, sum);
            }
        }
        return ans;
    }   
};