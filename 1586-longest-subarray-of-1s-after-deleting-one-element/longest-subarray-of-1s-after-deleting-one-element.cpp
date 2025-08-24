class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l = 0, ans = 0, n = nums.size(), cnt = 0;
        for(int r = 0; r<n; r++){
            if(nums[r] == 0) cnt++;
            while(cnt>1){
                if(nums[l] == 0) cnt--;
                l++; 
            }
            ans = max(ans, r-l+1);
        }
        return ans-1;
    }
};