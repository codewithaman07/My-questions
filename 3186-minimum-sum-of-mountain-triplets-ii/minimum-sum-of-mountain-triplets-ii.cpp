class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size(), ans = INT_MAX;
        vector<int>pre(n), suf(n);
        pre[0] = nums[0];
        suf[n-1] = nums[n-1];
        for(int i = 1; i<n; i++){
            pre[i] = min(pre[i-1], nums[i]);
        }
        for(int i = n-2; i>=0; i--){
            suf[i] = min(suf[i+1], nums[i]);
        }
        for(int i = 1; i<n-1; i++){
            if(nums[i] > pre[i-1] && nums[i] > suf[i+1]){
                ans = min(ans, nums[i]+pre[i-1]+suf[i+1]);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};


// class Solution {
// public:
//     int minimumSum(vector<int>& nums) {
//         int n = nums.size(), ans = INT_MAX;
//         for(int i = 0; i<n; i++){
//             for(int j = i+1; j<n; j++){
//                 for(int k = j+1; k<n; k++){
//                     if(i<j && j<k && nums[i] < nums[j] && nums[j] > nums[k]) ans = min(ans, nums[i]+nums[j]+nums[k]);
//                 }
//             }
//         }
//         return ans == INT_MAX ? -1 : ans;
//     }
// };