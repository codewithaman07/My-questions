class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& arr, vector<int>& nums) {
        int n = arr.size(), m = nums.size(), i = 0, j = 0, ans = 0;
        sort(arr.begin(), arr.end());
        sort(nums.begin(), nums.end());
        while(i<n && j<m){
            if(arr[i]<=nums[j]) ans++, i++, j++;
            else j++;
        }
        return ans;
    }
};