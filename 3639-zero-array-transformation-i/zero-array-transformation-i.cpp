class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int>diff(n,0), pre(n,0);
        for(auto it : queries){
            diff[it[0]]--;
            if(it[1]+1<n) diff[it[1]+1]++;
        }
        pre[0] = diff[0];
        for(int i = 1; i<n; i++){
            pre[i] = pre[i-1]+diff[i];
        }
        for(int i = 0; i<n; i++){
            nums[i] = nums[i]+pre[i];
        }
        for(int num : nums){
            if(num>0) return 0;
        }
        return 1;
    }
};