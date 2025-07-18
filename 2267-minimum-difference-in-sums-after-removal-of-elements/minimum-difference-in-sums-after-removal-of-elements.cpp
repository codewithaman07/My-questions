class Solution {
public:
    #define ll long long
    long long minimumDifference(vector<int>& nums) {
        ll n = nums.size()/3, sum = 0, ans = LLONG_MAX;
        vector<ll>pre(2*n, 0), suf(2*n+1, 0);
        priority_queue<ll>pq;
        priority_queue<ll, vector<ll>, greater<>>minh;
        for(int i = 0; i<2*n; i++){
            sum+=nums[i];
            pq.push(nums[i]);
            if(pq.size() > n){
                sum-=pq.top();
                pq.pop();
            }
            if(i>=n-1) pre[i] = sum;
        }
        sum = 0;
        for(int i = nums.size()-1; i>=n; i--){
            sum+=nums[i];
            minh.push(nums[i]);
            if(minh.size() > n){
                sum-=minh.top();
                minh.pop();
            }
            if(i<=2*n) suf[i] = sum;
        }
        for(int i = n-1; i<2*n; i++){
            ans = min(ans, pre[i]-suf[i+1]);
        }
        return ans;
    }
};