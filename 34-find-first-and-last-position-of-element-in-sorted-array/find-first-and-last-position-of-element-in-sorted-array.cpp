class Solution {
public:
    int ub(vector<int>&arr, int target){
        int l = 0, r = arr.size()-1, ans = arr.size();
        while(l<=r){
            int m = l+(r-l)/2;
            if(arr[m] > target){
                ans = m;
                r = m-1;
            }
            else l = m+1;
        }
        return ans-1;
    }
    int lb(vector<int>&arr, int target){
        int l = 0, r = arr.size()-1, ans = 0;
        while(l<=r){
            int m = l+(r-l)/2;
            if(arr[m] >= target){
                ans = m;
                r = m-1;
            }
            else l = m+1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if(!binary_search(nums.begin(), nums.end(), target)) return {-1,-1};
        int first = lb(nums, target);
        int last = ub(nums, target);
        return {first, last};
    }
};