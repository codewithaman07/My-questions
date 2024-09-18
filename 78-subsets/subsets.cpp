class Solution {
public:
    // void solve(vector<int>&nums, vector<vector<int>>&ans, vector<int>&temp, int idx){
    //     ans.push_back(temp);
    //     for(int i = idx; i<nums.size(); i++){
    //         temp.push_back(nums[i]);
    //         solve(nums,ans,temp,i+1);
    //         temp.pop_back();
    //     }
    // }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans = {{}};
        // vector<int>temp;
        // solve(nums,ans,temp,0);
        for(int num : nums){
            int n = ans.size();
            for(int i = 0; i<n; i++){
                vector<int>temp = ans[i];
                temp.push_back(num);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};