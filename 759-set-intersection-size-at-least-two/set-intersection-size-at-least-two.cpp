class Solution {
public:
    static bool cmp(vector<int>&a, vector<int>&b){
        if(a[1] == b[1]) return a[0]<b[0];
        else return a[1]<b[1];
    }
    int intersectionSizeTwo(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end(), cmp);
        vector<int>ans;
        ans.push_back(nums[0][1]-1);
        ans.push_back(nums[0][1]);
        for(int i = 1; i<nums.size(); i++){
            int s = nums[i][0];
            int e = nums[i][1];
            if(s>ans.back()){
                ans.push_back(e-1);
                ans.push_back(e);
            }
            else if(s == ans.back()) ans.push_back(e);
            else if(s > ans[ans.size()-2]) ans.push_back(e);
        }
        return ans.size();
    }
};