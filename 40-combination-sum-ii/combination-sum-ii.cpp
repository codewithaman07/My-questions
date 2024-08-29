class Solution {
public:
    void solve(vector<int>&nums, int k, vector<vector<int>>&ans, vector<int>&temp, int i, int sum){
        if(sum == k){
            ans.push_back(temp);
            return;
        }
        if(sum>k || nums.size()<=i) return;
        temp.push_back(nums[i]);
        solve(nums,k, ans,temp,i+1,sum+nums[i]);
        temp.pop_back();
        while(i+1 < nums.size() && nums[i] == nums[i+1]) i++;
        solve(nums,k,ans,temp,i+1, sum);
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int k) {
        vector<vector<int>>ans;
        vector<int>temp;
        sort(nums.begin(), nums.end());
        solve(nums,k,ans,temp,0,0);
        return ans;
    }
};