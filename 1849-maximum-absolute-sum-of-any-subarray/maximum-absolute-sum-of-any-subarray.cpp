class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size(), mini = 0, maxi = 0;
        for(int i = 0; i<n; i++){
            int x = nums[i];
            mini = min(mini+x, 0);
            maxi = max(maxi+x, 0);
        }
        return maxi-mini;
    }
};