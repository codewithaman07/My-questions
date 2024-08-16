class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 2, n = nums.size();
        if(n<=2) return n;
        for(int i = 2; i<n; i++){
            if(nums[j-2] != nums[i]){
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }
};