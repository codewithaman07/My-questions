class Solution {
public:
    #define ll long long
    long long minCost(vector<int>& arr, vector<int>& brr) {
        unordered_map<int,int>mp;
        int n = arr.size();
        vector<int>nums;
        int mini = INT_MAX;
        for(int i = 0; i<n; i++) mini = min(mini, arr[i]);
        for(int i = 0; i<n; i++) mini = min(mini, brr[i]);
        for(int num : arr) mp[num]++;
        for(int num : brr) mp[num]--;
        for(auto &[x,y] : mp){
            y = abs(y);
            if(y&1) return -1;
            for(int i = 0; i<y/2; i++){
                nums.push_back(x);
            }
        }
        sort(nums.begin(),nums.end());
        ll ans = 0;
        for(int i = 0; i<nums.size()/2; i++){
            ans+= min(nums[i], 2*mini);
        }
        return ans;
    }
};