class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size(), curr = 0, ans = 0;
        vector<int>freq(51,0);
        for(int &num : nums){
            freq[num] = max(freq[num], curr)+1; // max kitne k ban sakte h 
            if(num == k) curr++, ans++;
            ans = max(ans, freq[num]); // yhi saara khel ho rha h 
        }
        return ans;
    }
};

// class Solution {
// public:
//     int maxFrequency(vector<int>& nums, int k) {
//         int n = nums.size(), ans = 0;
//         int freq = count(nums.begin(), nums.end(), k);
//         for(int num = 1; num<=50; num++){
//             vector<int>temp(n,0);
//             for(int i = 0; i<n; i++){
//                 if(nums[i] == k) temp[i] = -1;
//                 else if(nums[i] == num) temp[i] = 1;
//             }
//             int curr = temp[0], maxi = temp[0];
//             for(int i = 1; i<n; i++){
//                 curr = max(temp[i], curr+temp[i]);
//                 maxi = max(maxi, curr);
//             }
//             ans = max(ans, maxi);
//         }
//         return ans+freq;

//     }
// };