class Solution {
public:
    bool fun(int m, int k,vector<int>&nums){
        int x = 1, n = nums.size(), sum = 0;
        for(int i = 0; i<n; i++){
            if(sum+nums[i]<=m) sum+=nums[i];
            else{
                x++;
                sum = nums[i];
            }
        }
        return x<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int l = INT_MIN, r = 0, n = nums.size();
        for(int i = 0; i<n; i++){
            l = max(l, nums[i]);
            r+=nums[i];
        }
        while(r-l>1){
            int m = l+(r-l)/2;
            if(fun(m,k,nums)) r = m;
            else l = m;
        }
        if(fun(l,k,nums)) return l;
        else return r;
    }
};