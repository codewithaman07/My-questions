class Solution {
public:
    bool fun(vector<int>&nums, int &k, int m, int &n){
        int cnt = 0;
        for(int i = 0; i<n; i++){
            if(nums[i]<=m){
                cnt++;
                i++;
            }
        }
        return cnt>=k;
    }
    int minCapability(vector<int>& nums, int k) {
       int n = nums.size(), l = *min_element(nums.begin(), nums.end());
       int r = *max_element(nums.begin(), nums.end()), ans = r;
        while(l<=r){
            int m = l+(r-l)/2;
            if(fun(nums,k,m,n)){
                ans = m;
                r = m-1;
            }
            else l = m+1;
        }
        return ans;
    }
};