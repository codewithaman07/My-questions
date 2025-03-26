class Solution {
    public int findKthLargest(int[] nums, int k) {
        Arrays.sort(nums);
        return nums[nums.length-k];
    }
}

// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         int mini = *min_element(nums.begin(), nums.end());
//         int maxi = *max_element(nums.begin(), nums.end());
//         vector<int>cnt(maxi-mini+1, 0);
//         for(int num : nums){
//             cnt[num-mini]++;
//         }
//         int n = cnt.size();
//         for(int i = n-1; i>=0; i--){
//             k-=cnt[i];
//             if(k<=0) return i+mini;
//         }
//         return -1;
//     }
// };

// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         priority_queue<int>pq(nums.begin(), nums.end());
//         for(int i = 0; i<k-1; i++) pq.pop();
//         return pq.top();
//     }
// };
