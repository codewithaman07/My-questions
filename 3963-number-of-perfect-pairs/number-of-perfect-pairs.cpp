class Solution {
public:
    #define ll long long
    long long perfectPairs(vector<int>& nums) {
        int n = nums.size();
        for(int &num : nums) num = abs(num);
        sort(nums.begin(), nums.end());
        int j = 0;
        ll ans = 0;
        for(int i = 0; i<n; i++){
            while(j<n && nums[j]<=2*nums[i]) j++;
            ans+=(j-i-1);
        }
        return ans;
    }
};