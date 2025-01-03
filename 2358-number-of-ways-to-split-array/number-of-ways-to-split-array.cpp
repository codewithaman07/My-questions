class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size(), cnt = 0;
        vector<long long>pre(n,0);
        pre[0] = nums[0];
        for(int i = 1; i<n; i++) pre[i] = pre[i-1]+nums[i];
        for(int i = 0; i<n-1; i++){
            long long x = pre[i];
            long long y = pre[n-1]-pre[i];
            if(x>=y) cnt++;
        }
        return cnt;
    }
};