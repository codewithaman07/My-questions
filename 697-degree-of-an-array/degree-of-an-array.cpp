class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size(), degree = 0;
        int ans = n;
        unordered_map<int,pair<int,int>>mp;
        unordered_map<int,int>mp2;
        for(int num : nums){
            degree = max(degree, ++mp2[num]);
        }
        unordered_set<int>st;
        for(auto [x,y] : mp2){
            if(y == degree) st.insert(x);
        }
        for(int i = 0; i<n; i++){
            if(!st.count(nums[i])) continue;
            if(!mp.count(nums[i])){
                mp[nums[i]] = {i, i};
            }
            else mp[nums[i]].second = max(i, mp[nums[i]].second);
        }
        for(auto [x,y] : mp){
            ans = min(ans, y.second-y.first+1);
        }
        return ans;
    }
};