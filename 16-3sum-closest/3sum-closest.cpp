class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size(), diff = INT_MAX, ans = -1;
        sort(nums.begin(),nums.end());
        for(int i = 0; i<n-2; i++){
            int j = i+1, k = n-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(abs(sum-target) < diff){
                    diff = abs(sum-target);
                    ans = sum;
                }
                if(sum < target) j++;
                else k--;
            }
        }
        return ans;
    }
};