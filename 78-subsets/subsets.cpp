class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans = {{}};
        for(auto num : nums){
            int n = ans.size();
            for(int j = 0; j<n; j++){
                vector<int>sub = ans[j];
                sub.push_back(num);
                ans.push_back(sub);
            }
        }
        return ans;
    }
};