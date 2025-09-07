class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), temp = nums[0];
        for(int i = 1; i<n; i++){
            if(nums[i] != temp) return 1;
        }
        return 0;
    }
};