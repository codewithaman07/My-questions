class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos = 0, neg = 0, n = nums.size();
        int l = upper_bound(nums.begin(), nums.end(), -1)-nums.begin();
        int r = upper_bound(nums.begin(), nums.end(), 0)-nums.begin();
        pos = n-r;
        neg = l;
        return max(pos,neg);
    }
};

// class Solution {
// public:
//     int maximumCount(vector<int>& nums) {
//         int pos = 0, neg = 0;
//         for(int num : nums){
//             if(num > 0) pos++;
//             else if(num < 0) neg++;
//         }
//         return max(pos,neg);
//     }
// };