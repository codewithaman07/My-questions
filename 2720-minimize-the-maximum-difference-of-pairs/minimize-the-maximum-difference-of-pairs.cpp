class Solution {
public:
    bool fun(vector<int>&nums, int mid, int p){
        int cnt = 0, i = 0, n = nums.size();
        while(i<n-1){
            if(nums[i+1]-nums[i]<=mid){
                cnt++;
                if(cnt>=p) return 1;
                i+=2;
            }
            else i++;
        }
        return cnt>=p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int l = 0, r = nums[n-1]-nums[0], ans = INT_MAX;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(fun(nums,mid,p)){
                ans = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        return ans;
    }
};