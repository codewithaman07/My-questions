class Solution {
public:
    bool fun(int m, vector<int>&nums, int n){
        int j = 0;
        int temp = nums[j];
        for(int i = 0; i<n; i++){
            if(temp <= m){
                j++;
                if(j == nums.size()) return 1;
                else temp = nums[j];
            }
            else temp-=m;
        }
        return 0;
    }
    int minimizedMaximum(int n, vector<int>& nums) {
        int l = 0, r = *max_element(nums.begin(), nums.end());
        while(l<r){
            int m = l+(r-l)/2;
            if(fun(m,nums,n)) r = m;
            else l = m+1;
        }
        return l;
    }
};