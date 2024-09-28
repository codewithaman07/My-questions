class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long  xorr = 0, n = nums.size();
        for(int i = 0; i<n; i++) xorr^=nums[i];
        int b1 = 0, b2 = 0;
        long long  rightSetBit = (xorr&(xorr-1))^xorr;
        for(int i = 0; i<n; i++){
            if((nums[i]*1ll) & rightSetBit) b1^=nums[i];
            else b2^=nums[i];
        }
        return {b1,b2};
    }
};