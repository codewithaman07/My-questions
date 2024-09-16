class Solution {
public:
    int findMinDifference(vector<string>& arr) {
        int n = arr.size();
        vector<int>nums;
        for(int i = 0; i<n; i++){
            string s = arr[i];
            int t = stoi(s.substr(0,2))*60 + stoi(s.substr(3,2));
            nums.push_back(t);
        }
        sort(nums.begin(), nums.end());
        int mini = INT_MAX;
        for(int i = 1; i<n; i++){
            mini = min(mini, nums[i]-nums[i-1]);
        }
        mini = min(nums[0]+1440-nums[n-1], mini);
        return mini;
    }
};