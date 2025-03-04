class Solution {
public:
    #define ll long long
    long long maxWeight(vector<int>& nums) {
        ll ans = 0;
        sort(nums.begin(),nums.end());
        int i = nums.size()-1;
        int n = (i+1)/4;
        int odd = (n+1)/2, even = n/2;
        while(odd--) ans+=nums[i--];
        while(even--) ans+=nums[i-1], i-=2;
        return ans;
    }
};