class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int n = nums.size();
        int mini = -1, maxi = -1;
        for(int l = 0, r = 0; r<n; r++){
            int num = nums[r];
            if(num < minK || num > maxK){
                l = r+1;
                continue;
            }
            if(num == minK) mini = r;
            if(num == maxK) maxi = r;
            ans+= max(min(maxi, mini)-l+1, 0);
        }
        return ans;
    }
};