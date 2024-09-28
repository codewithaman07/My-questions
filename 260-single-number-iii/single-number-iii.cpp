class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long  xorr = 0, n = nums.size();
        for(int i = 0; i<n; i++) xorr^=nums[i];
        int b1 = 0, b2 = 0;
        long long  rightSetBit = (xorr&(xorr-1))^xorr; // we can also use xorr & (-xorr);
        for(int i = 0; i<n; i++){
            if((nums[i]*1ll) & rightSetBit) b1^=nums[i];
            else b2^=nums[i];
        }
        return {b1,b2};
    }
};

// class Solution {
// public:
//     vector<int> singleNumber(vector<int>& nums) {
//         unordered_map<int,int>mpp;
//         for(auto x : nums){
//             mpp[x]++;
//         }
//         vector<int>ans;
//         for(auto x : mpp){
//             if(x.second == 1){
//                 ans.push_back(x.first);
//             }
//         }
//         return ans;
//     }
// };