class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        int n = nums.size();
        for(int i = 0; i<n-2; i++){
            int x = nums[i], y = nums[i+1], z = nums[i+2];
            if(x < y+z) return x+y+z;
        }
        return 0;
    }
};