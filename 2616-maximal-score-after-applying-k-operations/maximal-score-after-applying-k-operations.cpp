class Solution {
public:
    #define ll long long
    long long maxKelements(vector<int>& nums, int k) {
        ll ans = 0;
        int n = nums.size();
        priority_queue<int>pq;
        for(int i = 0; i<n; i++) pq.push(nums[i]);
        for(int i = 0; i<k; i++){
            int temp = pq.top();
            pq.pop();
            ans+=temp;
            pq.push((temp+2)/3);
        }
        return ans;
    }
};