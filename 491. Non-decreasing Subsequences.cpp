// Backtracking 

class Solution {
public:
    void solve(vector<int>&nums, int idx, vector<int>&temp, vector<vector<int>>&result){
        if(temp.size()>1){
            result.push_back(temp);
        }
        unordered_set<int>st;
        for(int i = idx; i<nums.size(); i++){
            if((temp.empty() || temp.back()<=nums[i]) && (st.find(nums[i]) == st.end())){
                st.insert(nums[i]);
                temp.push_back(nums[i]);
                solve(nums, i+1, temp, result);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;
        vector<int>temp;
        solve(nums,0,temp,result);
        return result; 
    }
};
