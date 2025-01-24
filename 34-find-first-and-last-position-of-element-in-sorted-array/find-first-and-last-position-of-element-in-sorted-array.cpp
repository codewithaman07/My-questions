class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if (!binary_search(nums.begin(), nums.end(), target)) return {-1, -1};
        int l = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int r = upper_bound(nums.begin(), nums.end(), target) - nums.begin()-1;
        return {l,r};
    }
};