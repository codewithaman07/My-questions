class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int mul) {
        int n = nums.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        for(int i = 0; i<n; i++) pq.push({nums[i],i});
        while(k--){
            pair<int,int>p = pq.top();
            pq.pop();
            int val = p.first, idx = p.second;
            nums[idx] = val*mul;
            pq.push({val*mul,idx});
        }
        return nums;
    }
};