class Solution {
public:
    void solve(int k, vector<vector<int>>&ans, vector<int>&temp, vector<int>&nums, int i){
        if(temp.size() == k){
            ans.push_back(temp);
            return;
        }
        if(i>=nums.size()) return;
        temp.push_back(nums[i]);
        solve(k,ans,temp,nums,i+1);
        temp.pop_back();
        solve(k,ans,temp,nums,i+1);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans; 
        vector<int>temp;
        vector<int>nums(n);
        for(int i = 1; i<=n ;i++) nums[i-1] = i;
        solve(k,ans,temp,nums,0);
        return ans;
    }
};