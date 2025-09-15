class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0, n = nums.size(), ans = 0;
        for(int j = 1; j<n; j++){
            if(nums[i] < nums[j]){
                ans++;
                i++;
            }
        }
        return ans;
    }
};