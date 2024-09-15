class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int x = 0, n = nums.size(), ans = -1;
        for(int i = 0; i<n; i++){
            if(x == nums[i]) x++;
            else{
                ans = x;
                break;
            }
        }
        return ans == -1 ? n:ans;
    }
};