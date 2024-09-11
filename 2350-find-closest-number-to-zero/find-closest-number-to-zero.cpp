class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int mini = INT_MAX;
        int n = nums.size();
        int pos = -1;
        sort(nums.begin(), nums.end());
        for(int i = 0; i<n; i++){
            if(abs(nums[i]) <= mini && nums[i]<=mini){
                pos = i;
                mini = abs(nums[i]);
            }
        }
        return nums[pos];
    }
};