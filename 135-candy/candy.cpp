class Solution {
public:
    int candy(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n,1);
        for(int i = 0; i<n-1; i++){
            if(nums[i]<nums[i+1]) ans[i+1] = 1+ans[i];
        }
        for(int i = n-1; i>0; i--){
            if(nums[i]<nums[i-1]) ans[i-1] = max(1+ans[i], ans[i-1]);
        }
        // for(int i : ans) cout<<i<<" ";
        return accumulate(ans.begin(), ans.end(),0);
    }
};