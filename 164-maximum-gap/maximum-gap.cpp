class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size(), ans = INT_MIN;
        if(n<2) return 0;
        sort(nums.begin(),nums.end());
        for(int i = 0; i<n-1; i++){
            int temp = nums[i+1]-nums[i];
            ans = max(ans, temp);
        }
        return ans;
    }
};