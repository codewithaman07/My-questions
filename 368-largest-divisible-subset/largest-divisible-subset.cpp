class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size(), last = 0, maxi = 1;
        sort(nums.begin(),nums.end());
        vector<int>dp(n,1), prev(n,-1);
        for(int i = 1; i<n; i++){
            for(int j = 0; j<i; j++){
                if(nums[i]%nums[j] == 0 && dp[i]<dp[j]+1){
                    dp[i] = 1+dp[j];
                    prev[i] = j;
                }
                if(dp[i]>maxi){
                    maxi = dp[i];
                    last = i;
                }
            }
        }
        vector<int>ans;
        while(last != -1){
            ans.push_back(nums[last]);
            last = prev[last];
        }
        return ans;
    }
};

// class Solution {
// public:
//     void solve(int idx, int prev, vector<int>&temp, vector<int>&nums, vector<int>&ans){
//         int n = nums.size();
//         if(idx>=n){
//             if(temp.size()>ans.size()) ans = temp;
//             return;
//         }
//         if(prev == -1 || nums[idx]%prev == 0){
//             temp.push_back(nums[idx]);
//             solve(idx+1,nums[idx], temp,nums,ans);
//             temp.pop_back();
//         }
//         solve(idx+1,prev, temp,nums,ans);
//     }
//     vector<int> largestDivisibleSubset(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         vector<int>temp, ans;
//         int prev = -1;
//         solve(0,prev,temp,nums,ans);
//         return ans;
//     }
// };
// class Solution {
// public:
//     void solve(int idx, vector<int>&temp, vector<int>&nums, vector<int>&ans){
//         int n = nums.size();
//         if(idx>=n){
//             if(temp.size()>ans.size()) ans = temp;
//             return;
//         }
//         for(int i = idx; i<n; i++){
//             bool f = 0;
//             if(temp.size() == 0)temp.push_back(nums[i]), f = 1;
//             else{
//                 if(nums[i]%temp.back() == 0) temp.push_back(nums[i]), f = 1;
//             }
//             solve(i+1, temp,nums,ans);
//             if(f) temp.pop_back();
//         }
//     }
//     vector<int> largestDivisibleSubset(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         vector<int>temp, ans;
//         solve(0,temp,nums,ans);
//         return ans;
//     }
// };