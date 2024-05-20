class Solution {
public:
    void solve(vector<int>&nums, int i, vector<int>&curr, vector<vector<int>>&subsets){
        int n = nums.size();
        if(i == n){
            subsets.push_back(curr);
            return;
        }
        curr.push_back(nums[i]);
        solve(nums, i+1, curr, subsets);
        curr.pop_back();
        solve(nums,i+1,curr,subsets);
    }
    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>> subsets;
        vector<int>curr;
        solve(nums,0,curr,subsets);
        int ans = 0;
        for(auto &it : subsets){
            int x = 0;
            for(auto &num : it){
                x^=num;
            }
            ans+=x;
        }
        return ans;
    }
};


class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int &num : nums){
            ans |= num;
        }
        ans = ans<<(n-1);
        return ans;
    }
};
