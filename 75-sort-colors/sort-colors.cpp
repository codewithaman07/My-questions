class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1, m = 0;
        while(m<=r){
            if(nums[m] == 0){
                swap(nums[l], nums[m]);
                l++, m++;
            }
            else if(nums[m] == 1) m++;
            else if(nums[r] == 2) r--;
            else{
                swap(nums[r], nums[m]);
                r--;
            }
        }
    }
};