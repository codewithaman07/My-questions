class Solution {
public:
    #define ll long long
    int minOperations(vector<int>& nums, int k) {
        ll n = nums.size(), op = 0;
        priority_queue<ll, vector<ll>, greater<ll>>pq(nums.begin(), nums.end());
        while(pq.size() >= 2){
            ll x = pq.top(); pq.pop();
            if(x >= k) return op;
            ll y = pq.top(); pq.pop();
            pq.push(min(x,y)*2 + max(x,y));
            op++;
        }
        return op;
    }
};