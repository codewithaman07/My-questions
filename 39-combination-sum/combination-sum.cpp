class Solution {
public:
    void solve(vector<int>&nums, int k, vector<vector<int>>&ans, vector<int>&temp, int i, int sum){
        if(sum == k){
            ans.push_back(temp);
            return;
        }
        if(sum>k || nums.size()<=i) return;
        sum+=nums[i];
        temp.push_back(nums[i]);
        solve(nums,k,ans,temp,i,sum);
        sum-=nums[i];
        temp.pop_back();
        solve(nums,k, ans,temp,i+1,sum);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int k) {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(nums,k,ans,temp,0,0);
        return ans;
    }
};