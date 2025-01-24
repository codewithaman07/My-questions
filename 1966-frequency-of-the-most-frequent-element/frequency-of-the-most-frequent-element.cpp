class Solution {
public:
    #define ll long long 
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size(), l = 0;
        sort(nums.begin(),nums.end());
        ll sum = 0, ans = 0;
        for(int r = 0; r<n; r++){
            sum+=nums[r];
            while((ll)(r-l+1)*nums[r] > sum+k){
                sum-=nums[l];
                l++;
            }
            ans = max((int)ans, r-l+1);
        }
        return ans;
    }
};