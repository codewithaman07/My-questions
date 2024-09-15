class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        sort(nums.begin(), nums.end());
        for(int i = 1; i<=n; i++){
            if(!binary_search(nums.begin(), nums.end(), i)) ans.push_back(i);
        }
        return ans;
    }
};