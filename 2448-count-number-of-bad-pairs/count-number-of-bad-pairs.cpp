class Solution {
public:
    #define ll long long 
    long long countBadPairs(vector<int>& nums) {
        ll ans = 0;
        int n = nums.size();
        vector<int>temp;
        for(int i = 0; i<n; i++){
            temp.push_back(nums[i]-i);
        }
        sort(temp.begin(),temp.end());
        for(int i = 0; i<n; i++){
            ll t = temp[i];
            int idx = upper_bound(temp.begin(), temp.end(), t) - temp.begin();
            ans+=(n-idx);
        }
        return ans;
    }
};