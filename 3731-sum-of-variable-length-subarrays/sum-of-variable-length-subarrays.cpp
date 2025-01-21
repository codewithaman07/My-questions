class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        vector<int>pre(n+1, 0);
        for(int i = 0; i<n; i++) pre[i+1] = pre[i]+nums[i];
        for(int i = 0; i<n; i++){
            int s = max(0, i-nums[i]);
            ans+= (pre[i+1]-pre[s]);
        }
        return ans;
    }
};