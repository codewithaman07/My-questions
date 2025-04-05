class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int ans = 0, n = nums.size();
        for(int num : nums){
            ans|=num;
        }
        return ans<<(n-1); // there is a pattern here setbits and n-1 zeros
    }
};

// class Solution {
// public:
//     int solve(int i, int ans, vector<int>&nums){
//         int n = nums.size();
//         if(i == n) return ans;
//         int a = solve(i+1,ans^nums[i], nums);
//         int b = solve(i+1,ans,nums);
//         return a+b;
//     }
//     int subsetXORSum(vector<int>& nums) {
//         return solve(0,0,nums);
//     }
// };

// class Solution {
// public:
//     void solve(int i, vector<int>&arr, vector<int>&nums, vector<vector<int>>&subsets){
//         int n = nums.size();
//         if(i == n){
//             subsets.push_back(arr);
//             return;
//         }
//         arr.push_back(nums[i]);
//         solve(i+1,arr,nums,subsets);
//         arr.pop_back();
//         solve(i+1,arr,nums,subsets);
//     }
//     int subsetXORSum(vector<int>& nums) {
//         vector<vector<int>>subsets;
//         vector<int>arr;
//         solve(0,arr,nums,subsets);
//         int ans = 0;
//         for(auto vec : subsets){
//             int sum = 0;
//             for(int num : vec){
//                 sum^=num;
//             }
//             ans+=sum;
//         }
//         return ans;
//     }
// };