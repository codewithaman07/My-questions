class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size(), cnt = 1;
        sort(nums.begin(),nums.end());
        int last = nums[0];
        for(int i = 0; i<n; i++){
            if(nums[i]-last > k){
                cnt++;
                last = nums[i];
            }
        }
        return cnt;
    }
};