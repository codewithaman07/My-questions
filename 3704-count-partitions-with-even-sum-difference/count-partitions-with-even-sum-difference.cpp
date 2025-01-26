class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size(), l = 0, ans = 0;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        for(int i = 0; i<n-1; i++){
            l+=nums[i];
            int r = sum-l;
            int temp = abs(l-r);
            if(temp%2 == 0) ans++;
        }
        return ans;
    }
};