class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0, j = 1; j<n; j++){
            if(nums[i]<nums[j]) ans++, i++;
        }
        return ans;
    }
};