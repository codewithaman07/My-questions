class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int mul) {
        int n = nums.size();
        for(int i = 0; i<k; i++){
            int idx = min_element(nums.begin(), nums.end())-nums.begin();
            nums[idx]*=mul;
        }
        return nums;
    }
};