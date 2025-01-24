class Solution {
public:
    int find(vector<int>&nums){
        int l = 0, r = nums.size()-1;
        if(nums[l] <= nums[r]) return l;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(nums[mid] > nums[mid+1]) return mid+1;
            if(nums[mid] < nums[mid-1]) return mid;
            if(nums[l] <= nums[mid]) l = mid+1;
            else r = mid-1;
        }
        return -1;
    }
    int bs(vector<int>&nums, int l, int r, int target){
        while(l<=r){
            int mid = l+(r-l)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) l = mid+1;
            else r = mid-1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int pivot = find(nums);
        int n = nums.size();
        if(pivot == 0) return bs(nums, 0, n-1, target);
        if(nums[0] <= target) return bs(nums, 0, pivot-1, target);
        else return bs(nums, pivot, n-1, target);
    }
};

// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         int l = 0, r = nums.size()-1;
//         while(l<=r){
//             int mid = l+(r-l)/2;
//             if(nums[mid] == target) return mid;
//             else if(nums[l] <= nums[mid]){
//                 if(nums[l] <= target && target <= nums[mid]) r = mid-1;
//                 else l = mid+1;
//             }
//             else{
//                 if(nums[mid] <= target && target <= nums[r]) l = mid+1;
//                 else r = mid-1;
//             }
//         }
//         return -1;
//     }
// };