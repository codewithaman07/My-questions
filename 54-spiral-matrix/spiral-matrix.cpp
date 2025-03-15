class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& nums) {
        int n = nums.size(), m = nums[0].size();
        vector<int>ans;
        int t = 0, b = n-1, l = 0, r = m-1;
        while(t<=b && l<=r){
            for(int i = l; i<=r; i++){
                ans.push_back(nums[t][i]);
            }
            t++;
            for(int i = t; i<=b; i++){
                ans.push_back(nums[i][r]);
            }
            r--;
            if(t<=b){
                for(int i = r; i>=l; i--){
                    ans.push_back(nums[b][i]);
                }
                b--;
            }
            if(l<=r){
                for(int i = b; i>=t; i--){
                    ans.push_back(nums[i][l]);
                }
                l++;
            }
        }
        return ans;
    }
};