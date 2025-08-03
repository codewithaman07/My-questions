class Solution {
public:
    int maxBalancedShipments(vector<int>& nums) {
        int n = nums.size(), maxi = 0, ans = 0;
        for(int i = 0; i<n; i++){
            maxi = max(maxi,nums[i]);
            if(nums[i] < maxi){
                ans++;
                maxi = 0;
            }
        }
        return ans;
    }
};