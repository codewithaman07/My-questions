class Solution {
public:
    #define ll long long
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        ll ans = 0;
        for(int i = 0; i<n; i++){
            int low = lower_bound(nums.begin()+i+1, nums.end(), lower-nums[i])-nums.begin()+i+1;
            int high = lower_bound(nums.begin()+i+1, nums.end(), upper-nums[i]+1)-nums.begin()+i+1;
            ans+=(high-low)*1ll;
        }
        return ans;
    }
};

// class Solution {
// public:
//     #define ll long long
//     long long countFairPairs(vector<int>& nums, int lower, int upper) {
//         ll ans = 0, n = nums.size();
//         for(int i = 0; i<n; i++){
//             for(int j = i+1; j<n; j++){
//                 ll x = nums[i]+nums[j];
//                 if(x >= lower && x <= upper) ans++;
//             }
//         }
//         return ans;
//     }
// };