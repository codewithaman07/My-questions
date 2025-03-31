class Solution {
public:
    #define ll long long
    long long putMarbles(vector<int>& nums, int k) {
        int n = nums.size();
        ll x = nums[0]+nums[n-1];
        k--;
        ll cnt = k, mini = x, maxi = x;
        vector<int>arr;
        for(int i = 0; i<n-1; i++){
            ll num = nums[i]+nums[i+1];
            arr.push_back(num);
        }
        priority_queue<int>pq(arr.begin(), arr.end());
        priority_queue<int, vector<int>, greater<>>pq2(arr.begin(), arr.end());
        while(cnt--){
            mini+=pq2.top();
            pq2.pop();
        }
        while(k--){
            maxi+=pq.top();
            pq.pop();
        }
        return maxi-mini;
    }
};